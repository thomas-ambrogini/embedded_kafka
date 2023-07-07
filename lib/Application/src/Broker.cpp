#include "Broker.hpp"

Broker::Broker(CommunicationType commType, const Endpoint &endpoint, const Logger &l) : communicationType(commType), logger(l)
{
    communication = CommunicationFactory::createCommunication(commType, endpoint, logger);
    logger.log("The broker created the communication");
}

Broker::~Broker()
{
    delete communication;
}

void Broker::start()
{
    while (true)
    {
        char clientBuffer[1024];

        Endpoint *clientSource = EndpointFactory::createEndpoint(communicationType);
        if (communication->read(clientBuffer, sizeof(clientBuffer), *clientSource) < 0)
        {
            logger.logError("Failed to receive message from client");
            break;
        }

        handleOperation(clientBuffer);

        logger.log("Request received from the client: %s", clientBuffer);
        clientSource->printEndpointInformation(logger);
    }
}

void Broker::handleOperation(const char *request)
{
    // Deserialize the request message from the string
    nlohmann::json deserializedRequest = nlohmann::json::parse(request);

    // Extract the fields from the deserialized request
    std::string operation = deserializedRequest["operation"];

    if (operation == "publish")
    {
        json jsonProducerMetadata = deserializedRequest["producerMetadata"];
        ProducerMetadata producerMetadata;
        producerMetadata.from_json(jsonProducerMetadata);

        std::string data = deserializedRequest["record"];
        Record record(strdup(data.c_str()));

        json jsonTopicMetadata = deserializedRequest["topicMetadata"];
        TopicMetadata topicMetadata;
        topicMetadata.from_json(jsonTopicMetadata);

        std::cout << "The producer with ID: " << producerMetadata.getId() << " sent the following record: " << data << " to be published on the topic: " << topicMetadata.getName() << std::endl;

        topicHandler.save(record, topicMetadata, producerMetadata);
        topicHandler.updateConsumers(topicMetadata);
    }
    else if (operation == "subscribe")
    {
        json jsonConsumerMetadata = deserializedRequest["consumerMetadata"];
        ConsumerMetadata consumerMetadata;
        consumerMetadata.from_json(jsonConsumerMetadata);

        json jsonTopicMetadata = deserializedRequest["topicMetadata"];
        TopicMetadata topicMetadata;
        topicMetadata.from_json(jsonTopicMetadata);

        std::cout << "The consumer with ID: " << consumerMetadata.getId() << " wants to subscribe on the topic: " << topicMetadata.getName() << std::endl;

        topicHandler.subscribe(consumerMetadata, topicMetadata, communication);
    }
    else if (operation == "unsubscribe")
    {
    }
}
