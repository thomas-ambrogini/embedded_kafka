#ifndef COMMUNICATIONFACTORY_H
#define COMMUNICATIONFACTORY_H

#include "Communication.hpp"
#include "CommunicationType.hpp"
#include "UDPSocketCommunication.hpp"
#include "UDPEndpoint.hpp"
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

        default:
            return nullptr;
        }
    }
};

#endif
