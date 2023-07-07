#ifndef BROKER_H
#define BROKER_H

#include "BrokerMetadata.hpp"
#include "Endpoint.hpp"
#include "CommunicationType.hpp"
#include "CommunicationFactory.hpp"
#include "EndpointFactory.hpp"
#include "ProducerMetadata.hpp"

class Broker
{
public:
    Broker(enum CommunicationType commType, const Endpoint &endpoint, const Logger &logger);
    ~Broker();

    void start();

private:
    BrokerMetadata brokerMetadata;
    Communication *communication;
    const CommunicationType communicationType;
    const Logger &logger;

    void handleOperation(const char *request);
};

#endif
