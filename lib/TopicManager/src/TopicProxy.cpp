#include "TopicProxy.hpp"

TopicProxy::TopicProxy(const CommunicationType type, TopicMetadata t, const Logger &l) : Topic(t), communicationType(type), logger(l), brokerMetadata(new UDPEndpoint(1235))
{
    Endpoint *sourceEndpoint = EndpointFactory::createEndpoint(communicationType);
    communication = CommunicationFactory::createCommunication(communicationType, *sourceEndpoint, logger);
}

TopicProxy::~TopicProxy()
{
    std::cout << "TopicProxy destructor called." << std::endl;
}

void TopicProxy::publish(ProducerMetadata producerMetadata, Record record)
{
    json request;
    request["operation"] = "publish";
    request["producerMetadata"] = producerMetadata;
    request["topicMetadata"] = topicMetadata;
    request["record"] = record.getData();

    std::string requestString = request.dump();
    logger.log("Sending the following message: %s", requestString.c_str());

    communication->write(requestString.c_str(), requestString.size() + 1, *brokerMetadata.getEndpoint());
}

void TopicProxy::subscribe(ConsumerMetadata consumerMetadata)
{
    json request;
    request["operation"] = "subscribe";
    request["consumerMetadata"] = consumerMetadata;
    request["topicMetadata"] = topicMetadata;

    std::string requestString = request.dump();
    logger.log("Sending the following message: %s", requestString);

    communication->write(requestString.c_str(), requestString.size() + 1, *brokerMetadata.getEndpoint());
}

void TopicProxy::unsubscribe(ConsumerMetadata consumerMetadata)
{
    json request;
    request["operation"] = "unsubscribe";
    request["consumerMetadata"] = consumerMetadata;
    request["topicMetadata"] = topicMetadata;

    std::string requestString = request.dump();
    logger.log("Sending the following message: %s", requestString);

    communication->write(requestString.c_str(), requestString.size() + 1, *brokerMetadata.getEndpoint());
}

void TopicProxy::setBrokerMetadata(BrokerMetadata b)
{
    brokerMetadata = b;
}

BrokerMetadata TopicProxy::getBrokerMetadata() const
{
    return brokerMetadata;
}
