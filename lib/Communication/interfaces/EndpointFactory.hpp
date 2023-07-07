#ifndef ENDPOINTFACTORY_H
#define ENDPOINTFACTORY_H

#include "Communication.hpp"
#include "CommunicationType.hpp"
#include "UDPSocketCommunication.hpp"
#include "UDPEndpoint.hpp"
#include "Logger.hpp"

class EndpointFactory
{
public:
    static Endpoint *createEndpoint(CommunicationType commType)
    {
        switch (commType)
        {
        case UDP:
            return new UDPEndpoint();
            break;

        default:
            return nullptr;
        }
    }
};

#endif
