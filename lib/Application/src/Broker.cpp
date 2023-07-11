#include "Broker.hpp"

Broker::Broker(CommunicationType commType, const Endpoint &endpoint, const Logger &l) : communicationType(commType), logger(l), communication(CommunicationFactory::createCommunication(commType, endpoint, logger)), topicHandler(communicationType, logger, communication)
{
    logger.log("[Broker] The broker created the communication");
}

Broker::Broker(CommunicationType commType, const Endpoint &endpoint, const Logger &l, std::vector<std::string> topicNames) : communicationType(commType), logger(l), communication(CommunicationFactory::createCommunication(commType, endpoint, logger)), topicHandler(communicationType, logger, communication, topicNames)
{
    logger.log("[Broker] The broker created the communication");
}

Broker::~Broker()
{
    delete communication;
}

void Broker::start()
{
    char clientRequest[1024];
    Endpoint *sourceEndpoint = EndpointFactory::createEndpoint(communicationType);

    while (true)
    {
        if (communication->read(clientRequest, sizeof(clientRequest), *sourceEndpoint) < 0)
        {
            logger.logError("[Broker] Failed to receive message from client");
            break;
        }
        logger.log("[Broker] Request received from the client: %s", clientRequest);
        sourceEndpoint->printEndpointInformation(logger);

        handleOperation(clientRequest, sourceEndpoint);
    }

    delete sourceEndpoint;
}

void Broker::handleOperation(const char *request, Endpoint *sourceEndpoint)
{
    nlohmann::json deserializedRequest = nlohmann::json::parse(request);
    std::string operation = deserializedRequest["operation"];

    logger.log("[Broker] Operation to do: %s", operation.c_str());

    if (operation == "publish")
    {
        json jsonProducerMetadata = deserializedRequest["producerMetadata"];
        ProducerMetadata producerMetadata;
        producerMetadata.from_json(jsonProducerMetadata);

        std::string data = deserializedRequest["record"];
        Record record(data);

        json jsonTopicMetadata = deserializedRequest["topicMetadata"];
        TopicMetadata topicMetadata;
        topicMetadata.from_json(jsonTopicMetadata);

        logger.log("[Broker] The producer with ID: %d, sent the following record: %s to be published on the topic: %s", producerMetadata.getId(), record.getData().c_str(), topicMetadata.getName().c_str());

        topicHandler.save(record, topicMetadata, producerMetadata);
        // topicHandler.updateConsumers(topicMetadata);
    }
    else if (operation == "subscribe")
    {
        json jsonConsumerMetadata = deserializedRequest["consumerMetadata"];
        ConsumerMetadata consumerMetadata;
        consumerMetadata.from_json(jsonConsumerMetadata);
        if (consumerMetadata.getEndpoint() == nullptr)
        {
            consumerMetadata.setEndpoint(sourceEndpoint);
        }

        json jsonTopicMetadata = deserializedRequest["topicMetadata"];
        TopicMetadata topicMetadata;
        topicMetadata.from_json(jsonTopicMetadata);

        logger.log("[Broker] The consumer with ID: %d wants to subscribe on the topic: %s", consumerMetadata.getId(), topicMetadata.getName().c_str());

        topicHandler.subscribe(consumerMetadata, topicMetadata);
    }
    else if (operation == "unsubscribe")
    {
        json jsonConsumerMetadata = deserializedRequest["consumerMetadata"];
        ConsumerMetadata consumerMetadata;
        consumerMetadata.from_json(jsonConsumerMetadata);

        json jsonTopicMetadata = deserializedRequest["topicMetadata"];
        TopicMetadata topicMetadata;
        topicMetadata.from_json(jsonTopicMetadata);

        logger.log("[Broker] The consumer with ID: %d wants to unsubscribe from the topic: %s", consumerMetadata.getId(), topicMetadata.getName().c_str());

        topicHandler.unsubscribe(consumerMetadata, topicMetadata);
    }
    else if (operation == "poll")
    {
        json jsonConsumerMetadata = deserializedRequest["consumerMetadata"];
        ConsumerMetadata consumerMetadata;
        consumerMetadata.from_json(jsonConsumerMetadata);
        if (consumerMetadata.getEndpoint() == nullptr)
        {
            consumerMetadata.setEndpoint(sourceEndpoint);
        }

        json jsonTopicMetadata = deserializedRequest["topicMetadata"];
        TopicMetadata topicMetadata;
        topicMetadata.from_json(jsonTopicMetadata);

        logger.log("[Broker] The consumer with ID: %d wants to unsubscribe from the topic: %s", consumerMetadata.getId(), topicMetadata.getName().c_str());

        topicHandler.poll(consumerMetadata, topicMetadata);
    }
}
