#ifdef SOC_AM64X

#include "RPMessageEndpoint.hpp"

RPMessageEndpoint::RPMessageEndpoint() : coreId(-1), serviceEndpoint(-1)
{
}

RPMessageEndpoint::RPMessageEndpoint(uint32_t c, uint16_t e) : coreId(c), serviceEndpoint(e)
{
}

RPMessageEndpoint::~RPMessageEndpoint()
{
}

void RPMessageEndpoint::printEndpointInformation(const Logger &logger) const
{
    logger.log("[RPMessage] CoreId: %d, ServiceEndpoint: %d", coreId, serviceEndpoint);
}

void RPMessageEndpoint::to_json(json &j) const
{
}

void RPMessageEndpoint::from_json(const json &j)
{
}

void RPMessageEndpoint::setCoreId(uint32_t c)
{
    coreId = c;
}

void RPMessageEndpoint::setServiceEndpoint(uint16_t s)
{
    serviceEndpoint = s;
}

uint32_t RPMessageEndpoint::getCoreId() const
{
    return coreId;
}

uint16_t RPMessageEndpoint::getServiceEndpoint() const
{
    return serviceEndpoint;
}

#endif