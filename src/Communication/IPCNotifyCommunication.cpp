#ifdef SOC_AM64X

#include "IPCNotifyCommunication.hpp"

IPCNotifyCommunication::IPCNotifyCommunication(const IPCNotifyEndpoint &ep, const Logger &l) : Communication(l), endpoint(ep)
{
    int32_t status;

    status = IpcNotify_registerClient(endpoint.getClientId(), endpoint.getHandler(), NULL);
    DebugP_assert(status == SystemP_SUCCESS);
}

IPCNotifyCommunication::~IPCNotifyCommunication()
{
}

int IPCNotifyCommunication::read(char *buffer, size_t bufferSize, Endpoint &source)
{
    /*
        The Callbacks are used in IPCNotify to handle messages.
    */
}

int IPCNotifyCommunication::write(const char *message, size_t messageSize, const Endpoint &destination)
{
    uint32_t msgValue = strtoul(message, NULL, 10);
    int32_t status;

    const IPCNotifyEndpoint &IpcNotifyDestination = static_cast<const IPCNotifyEndpoint &>(destination);

    status = IpcNotify_sendMsg(IpcNotifyDestination.getCoreId(), endpoint.getCoreId(), msgValue, 1);
    DebugP_assert(status == SystemP_SUCCESS);

    return 1;
}

#endif
