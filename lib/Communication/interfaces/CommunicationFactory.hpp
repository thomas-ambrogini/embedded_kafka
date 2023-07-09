#ifndef COMMUNICATIONFACTORY_H
#define COMMUNICATIONFACTORY_H

#include "Communication.hpp"
#include "CommunicationType.hpp"
#include "UDPSocketCommunication.hpp"
#include "RPMessageCommunication.hpp"
#include "UDPEndpoint.hpp"
#include "RPMessageEndpoint.hpp"
#include "Logger.hpp"

class CommunicationFactory
{
public:
    static Communication *createCommunication(CommunicationType commType, const Endpoint &endpoint, const Logger &logger)
    {
        switch (commType)
        {
        case UDP:
            return new UDPSocketCommunication(dynamic_cast<const UDPEndpoint &>(endpoint), logger);
            break;
        case RPMessage:
            return new RPMessageCommunication(dynamic_cast<const RPMessageEndpoint &>(endpoint), logger);
            break;

        default:
            return nullptr;
        }
    }
};

#endif
