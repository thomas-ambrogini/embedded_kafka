#ifndef TOPICPROXY_H
#define TOPICPROXY_H

#include <vector>
#include "Topic.hpp"
#include "ConsumerMetadata.hpp"
#include "LocalOffset.hpp"
#include "BrokerMetadata.hpp"
#include "Communication.hpp"
#include "TopicMetadata.hpp"
#include "CommunicationFactory.hpp"
#include "CommunicationType.hpp"
#include "EndpointFactory.hpp"
#include "Endpoint.hpp"
#include "json.hpp"

using json = nlohmann::json;

class TopicProxy : public Topic
{
public:
    TopicProxy(CommunicationType communicationType, TopicMetadata topicMetadata, const Logger &logger);

    ~TopicProxy();

    void publish(ProducerMetadata producerMetadata, Record record) override;
    void subscribe(ConsumerMetadata consumerMetadata) override;
    void unsubscribe(ConsumerMetadata consumerMetadata) override;
    // char*  poll(ConsumerMetadata consumerMetadata) override;

    void setBrokerMetadata(BrokerMetadata b);
    BrokerMetadata getBrokerMetadata() const;

private:
    const CommunicationType communicationType;
    const Logger &logger;
    BrokerMetadata brokerMetadata;
    Communication *communication;

    int findConsumer(int consumerId);
};

#endif