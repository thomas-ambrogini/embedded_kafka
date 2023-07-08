#ifndef BROKER_H
#define BROKER_H

#include "BrokerMetadata.hpp"
#include "Endpoint.hpp"
#include "CommunicationType.hpp"
#include "CommunicationFactory.hpp"
#include "EndpointFactory.hpp"
#include "ProducerMetadata.hpp"
#include "Record.hpp"
#include "ConsumerMetadata.hpp"
#include "TopicHandler.hpp"

class Broker
{
public:
    Broker(enum CommunicationType commType, const Endpoint &endpoint, const Logger &logger);
    ~Broker();

    void start();

private:
    BrokerMetadata brokerMetadata;
    const CommunicationType communicationType;
    const Logger &logger;
    Communication *communication;
    TopicHandler topicHandler;

    void handleOperation(const char *request, Endpoint *sourceEndpoint);
};

#endif
