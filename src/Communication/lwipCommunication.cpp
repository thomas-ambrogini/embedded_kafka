#ifdef SOC_AM64X

#include "lwipCommunication.hpp"


/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#define SOCK_HOST_SERVER_IP6  ("FE80::12:34FF:FE56:78AB")

#define SOCK_HOST_SERVER_PORT  (8888)

#define APP_SOCKET_MAX_RX_DATA_LEN (1024U)

#define APP_SOCKET_NUM_ITERATIONS (5U)

#define MAX_IPV4_STRING_LEN (16U)

static const uint8_t APP_CLIENT_TX_MSG1[] = "Greetings from Texas Instruments!";

static const uint8_t APP_CLIENT_TX_MSG2[] = "This is a sample message";

#if !LWIP_SOCKET
#error "LWIP_SOCKET is not set! enable socket support in LwIP"
#endif


/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

static uint8_t gRxDataBuff[APP_SOCKET_MAX_RX_DATA_LEN];

static struct App_hostInfo_t gHostInfo;

static char   gHostServerIp4[MAX_IPV4_STRING_LEN] = "192.168.1.1";


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

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

void initialization() {
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
}

void fillHostSocketInfo(struct App_hostInfo_t* pHostInfo) {
    ip_addr_t ipAddr;
    int32_t addr_ok;
    memset(&pHostInfo->socketAddr, 0, sizeof(pHostInfo->socketAddr));

    struct sockaddr_in*  pAddr = &pHostInfo->socketAddr;
    IP_SET_TYPE_VAL(dstaddr, IPADDR_TYPE_V4);
    addr_ok = ip4addr_aton(gHostServerIp4, ip_2_ip4(&ipAddr));
    pAddr->sin_len = sizeof(pHostInfo->socketAddr);
    pAddr->sin_family = AF_INET;
    pAddr->sin_port = PP_HTONS(SOCK_HOST_SERVER_PORT);
    inet_addr_from_ip4addr(&pAddr->sin_addr, ip_2_ip4(&ipAddr));
    EnetAppUtils_assert(addr_ok);
}

void startEverything(void* pArg) {
    struct sockaddr* pAddr = pArg;
    int32_t ret = 0;
    struct timeval opt = {0}, tv = {0};
    fd_set readset = {0}, writeset = {0}, errset = {0};

    sock = lwip_socket(pAddr->sa_family, SOCK_STREAM, 0);
    if (sock < 0)
    {
        EnetAppUtils_print("ERR: unable to open socket\r\n");
        continue;
    }

    /* connect */
    ret = lwip_connect(sock, pAddr, pAddr->sa_len);
    if (ret != 0)
    {
        ret = lwip_close(sock);
        EnetAppUtils_print("ERR: unable to connect\r\n");
        continue;
    }
    EnetAppUtils_print("Connected to host\r\n");

    /* set recv timeout (100 ms) */
    opt.tv_sec = 0;
    opt.tv_usec = 100 * 1000;
    ret = lwip_setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &opt, sizeof(opt));
    if (ret != 0)
    {
        ret = lwip_close(sock);
        EnetAppUtils_print("ERR: set sockopt failed\r\n");
        continue;
    }
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

    initialization();

    DebugP_log("Network is UP ...\r\n");
    ClockP_sleep(1);

    fillHostSocketInfo(&gHostInfo);



    App_shutdownNetworkStack();
    return 0;
}



lwipCommunication::~lwipCommunication()
{
    int32_t ret = 0;
    ret = lwip_close(sock);
}

int lwipCommunication::read(char *buffer, size_t bufferSize, Endpoint &source)
{
    // uint32_t status;
    // uint16_t remoteCoreId, remoteCoreServiceEndpoint;
    // uint16_t size = static_cast<uint16_t>(bufferSize);

    // status = RPMessage_recv(&msgObject,
    //                         buffer, &size,
    //                         &remoteCoreId,
    //                         &remoteCoreServiceEndpoint,
    //                         SystemP_WAIT_FOREVER);

    // DebugP_assert(status == SystemP_SUCCESS);

    // static_cast<RPMessageEndpoint &>(source).setCoreId(remoteCoreId);
    // static_cast<RPMessageEndpoint &>(source).setServiceEndpoint(remoteCoreServiceEndpoint);

    ret = lwip_read(sock, gRxDataBuff, APP_SOCKET_MAX_RX_DATA_LEN);
            if (ret <= 0)
            {
                 ret = lwip_close(sock);
                 EnetAppUtils_print("ERR: socket read failed\r\n");
                 continue;
            }
            gRxDataBuff[ret] = '\0';
            EnetAppUtils_print("Message from host: %s\r\n", gRxDataBuff);

    return 1;
}

int lwipCommunication::write(const char *message, size_t messageSize, const Endpoint &destination)
{
    // const RPMessageEndpoint &rpMessageDestination = static_cast<const RPMessageEndpoint &>(destination);

    // uint32_t status;
    // uint16_t msgSize;

    // msgSize = strlen(message) + 1;

    // status = RPMessage_send(
    //     const_cast<char *>(message), msgSize,
    //     rpMessageDestination.getCoreId(),
    //     rpMessageDestination.getServiceEndpoint(),
    //     RPMessage_getLocalEndPt(&msgObject),
    //     SystemP_WAIT_FOREVER);

    // DebugP_assert(status == SystemP_SUCCESS);

    ret = lwip_write(sock, APP_CLIENT_TX_MSG1, sizeof(APP_CLIENT_TX_MSG1));
    if (ret != sizeof(APP_CLIENT_TX_MSG1))
    {
        ret = lwip_close(sock);
        EnetAppUtils_print("ERR: socket write failed\r\n");
        continue;
    }

    return 1;
}

#endif
