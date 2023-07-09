#ifndef ENDPOINTFACTORY_H
#define ENDPOINTFACTORY_H

#include "Communication.hpp"
#include "CommunicationType.hpp"
#include "Logger.hpp"

#ifdef __unix__
#include "UDPEndpoint.hpp"
#include "UDPSocketCommunication.hpp"
#endif

#ifdef SOC_AM64X
#include "RPMessageCommunication.hpp"
#include "RPMessageEndpoint.hpp"
#endif

class EndpointFactory
{
public:
    static Endpoint *createEndpoint(CommunicationType commType);
};

#endif
