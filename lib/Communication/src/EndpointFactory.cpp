#include "EndpointFactory.hpp"

Endpoint *EndpointFactory::createEndpoint(CommunicationType commType)
{
    switch (commType)
    {
    case UDP:
#ifdef __unix__
        return new UDPEndpoint();
#endif
        break;

    case RPMessage:
#ifdef __TI_ARM__
        return new RPMessageEndpoint();
#endif
        break;
    default:
        return nullptr;
    }

    return nullptr;
}
