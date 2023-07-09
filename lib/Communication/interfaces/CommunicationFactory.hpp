#ifndef COMMUNICATIONFACTORY_H
#define COMMUNICATIONFACTORY_H

#include "Communication.hpp"
#include "CommunicationType.hpp"
#include "Logger.hpp"

#ifdef __unix__
#include "UDPEndpoint.hpp"
#include "UDPSocketCommunication.hpp"
#endif

#ifdef __TI_ARM__
#include "RPMessageCommunication.hpp"
#include "RPMessageEndpoint.hpp"
#endif

class CommunicationFactory
{
public:
    static Communication *createCommunication(CommunicationType commType, const Endpoint &endpoint, const Logger &logger);
};

#endif
