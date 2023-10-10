#ifdef SOC_AM64X

#include "lwipCommunication.hpp"

static void setupNetworkStack()
{
    sys_sem_t pInitSem;
    const err_t err = sys_sem_new(&pInitSem, 0);
    EnetAppUtils_assert(err == ERR_OK);

    tcpip_init(App_tcpipInitCompleteCb, &pInitSem);

    /* wait for TCP/IP initialization to complete */
    sys_sem_wait(&pInitSem);
    sys_sem_free(&pInitSem);

    return;
}

static void App_tcpipInitCompleteCb(void *pArg)
{
    sys_sem_t *pSem = (sys_sem_t *)pArg;
    EnetAppUtils_assert(pArg != NULL);

    /* init randomizer again (seed per thread) */
    srand((unsigned int)sys_now() / 1000);

    App_setupNetif();

    App_allocateIPAddress();

    sys_sem_signal(pSem);
}

static void App_setupNetif()
{
    ip4_addr_t ipaddr, netmask, gw;

    ip4_addr_set_zero(&gw);
    ip4_addr_set_zero(&ipaddr);
    ip4_addr_set_zero(&netmask);

    DebugP_log("Starting lwIP, local interface IP is dhcp-enabled\r\n");

    for (uint32_t i = 0U; i < ENET_SYSCFG_NETIF_COUNT; i++)
    {
        /* Open the netif and get it populated*/
        LwipifEnetApp_netifOpen(NETIF_INST_ID0 + i, &ipaddr, &netmask, &gw);
        g_pNetif[NETIF_INST_ID0 + i] = LwipifEnetApp_getNetifFromId(NETIF_INST_ID0);
        netif_set_status_callback(g_pNetif[NETIF_INST_ID0 + i], App_netifStatusChangeCb);
        netif_set_link_callback(g_pNetif[NETIF_INST_ID0 + i], App_netifLinkChangeCb);
        netif_set_up(g_pNetif[NETIF_INST_ID0 + i]);
    }
    LwipifEnetApp_startSchedule(g_pNetif[ENET_SYSCFG_DEFAULT_NETIF_IDX]);
}

static void App_allocateIPAddress()
{
    sys_lock_tcpip_core();
    for (uint32_t i = 0U; i < ENET_SYSCFG_NETIF_COUNT; i++)
    {
        dhcp_set_struct(g_pNetif[NETIF_INST_ID0 + i], &g_netifDhcp[NETIF_INST_ID0 + i]);

        const err_t err = dhcp_start(g_pNetif[NETIF_INST_ID0 + i]);
        EnetAppUtils_assert(err == ERR_OK);
    }
    sys_unlock_tcpip_core();
    return;
}

static void App_shutdownNetworkStack()
{
    LwipifEnetApp_netifClose(NETIF_INST_ID0);
    return;
}

lwipCommunication::lwipCommunication(const RPMessageEndpoint &ep, const Logger &l) : Communication(l), endpoint(ep)
{
    // endpoint.printEndpointInformation(logger);
    // int32_t status;
    // RPMessage_CreateParams createParams;

    // RPMessage_CreateParams_init(&createParams);
    // createParams.localEndPt = endpoint.getServiceEndpoint();
    // status = RPMessage_construct(&msgObject, &createParams);

    // DebugP_assert(status == SystemP_SUCCESS);

    Enet_Type enetType;
    uint32_t instId;

    // Initializations Required for CPSW
    EnetApp_getEnetInstInfo(&enetType, &instId);
    EnetAppUtils_enableClocks(enetType, instId);

    const int32_t status = EnetApp_driverOpen(enetType, instId);

    if (ENET_SOK != status)
    {
        EnetAppUtils_print("Failed to open ENET: %d\r\n", status);
        EnetAppUtils_assert(false);
        return -1;
    }

    EnetApp_addMCastEntry(enetType,
                          instId,
                          EnetSoc_getCoreId(),
                          BROADCAST_MAC_ADDRESS,
                          CPSW_ALE_ALL_PORTS_MASK);

    App_setupNetworkStack();

    while (false == App_isNetworkUp(netif_default))
    {
        DebugP_log("Waiting for network UP ...\r\n");
        ClockP_sleep(2);
    }

    DebugP_log("Network is UP ...\r\n");
    ClockP_sleep(1);
    AppTcp_startClient();

    App_shutdownNetworkStack();
    return 0;
}

lwipCommunication::~lwipCommunication()
{
    RPMessage_destruct(&msgObject);
}

int lwipCommunication::read(char *buffer, size_t bufferSize, Endpoint &source)
{
    uint32_t status;
    uint16_t remoteCoreId, remoteCoreServiceEndpoint;
    uint16_t size = static_cast<uint16_t>(bufferSize);

    status = RPMessage_recv(&msgObject,
                            buffer, &size,
                            &remoteCoreId,
                            &remoteCoreServiceEndpoint,
                            SystemP_WAIT_FOREVER);

    DebugP_assert(status == SystemP_SUCCESS);

    static_cast<RPMessageEndpoint &>(source).setCoreId(remoteCoreId);
    static_cast<RPMessageEndpoint &>(source).setServiceEndpoint(remoteCoreServiceEndpoint);

    return 1;
}

int lwipCommunication::write(const char *message, size_t messageSize, const Endpoint &destination)
{
    const RPMessageEndpoint &rpMessageDestination = static_cast<const RPMessageEndpoint &>(destination);

    uint32_t status;
    uint16_t msgSize;

    msgSize = strlen(message) + 1;

    status = RPMessage_send(
        const_cast<char *>(message), msgSize,
        rpMessageDestination.getCoreId(),
        rpMessageDestination.getServiceEndpoint(),
        RPMessage_getLocalEndPt(&msgObject),
        SystemP_WAIT_FOREVER);

    DebugP_assert(status == SystemP_SUCCESS);

    return 1;
}

#endif
