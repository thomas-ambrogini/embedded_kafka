#ifndef TOPICHANDLER_H
#define TOPICHANDLER_H

#include "Record.hpp"
#include "TopicMetadata.hpp"
#include "ProducerMetadata.hpp"
#include "Topic.hpp"
#include "Communication.hpp"
#include "Callback.hpp"
#include "CommunicationType.hpp"
#include "Logger.hpp"

class TopicHandler
{
public:
    TopicHandler(const CommunicationType communicationType, const Logger &logger);

    void save(Record record, TopicMetadata topicMetadata, ProducerMetadata producerMetadata);
    void subscribe(ConsumerMetadata consumerMetadata, TopicMetadata topicMetadata, Communication *communication);
    void updateConsumers(TopicMetadata topicMetadata);

private:
    std::vector<Topic *> topics;
    std::vector<Callback> callbacks;
    const CommunicationType communicationType;
    const Logger &logger;

    void init();
    int findTopicIndex(TopicMetadata topicMetadata);
};

#endif