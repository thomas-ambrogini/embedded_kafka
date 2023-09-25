#include "IPCNotifyEndpoint.hpp"

IPCNotifyEndpoint::IPCNotifyEndpoint(uint32_t coreId, uint16_t clientId, std::function<void(uint32_t, uint16_t, uint32_t, void *)> handler) : coreId(coreId), clientId(clientId), handler_(handler)
{
}

IPCNotifyEndpoint::~IPCNotifyEndpoint()
{
}

void IPCNotifyEndpoint::printEndpointInformation(const Logger &logger) const
{
    logger.log("[RPMessage] CoreId: %d, ClientId: %d", coreId, clientId);
}

uint32_t IPCNotifyEndpoint::getCoreId() const
{
    return coreId;
}

void IPCNotifyEndpoint::setCoreId(uint32_t c)
{
    coreId = c;
}

uint16_t IPCNotifyEndpoint::getClientId() const
{
    return clientId;
}

void IPCNotifyEndpoint::setClientId(uint16_t c)
{
    clientId = c;
}

std::function<void(uint32_t, uint16_t, uint32_t, void *)> &IPCNotifyEndpoint::getHandler()
{
    return handler_;
}

void IPCNotifyEndpoint::setHandler(std::function<void(uint32_t, uint16_t, uint32_t, void *)> handler)
{
    handler_ = handler;
}
