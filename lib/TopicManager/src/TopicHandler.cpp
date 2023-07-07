#include "TopicHandler.hpp"

TopicHandler::TopicHandler(const CommunicationType c, const Logger &l) : communicationType(c), logger(l)
{
    init();
}

void TopicHandler::init()
{
    std::string topicName = "Topic1";
    TopicMetadata topicMetadata(topicName);
    Topic *topic = new Topic(topicMetadata);
    topics.push_back(topic);

    Callback callback(topicMetadata);
    callbacks.push_back(callback);
}

void TopicHandler::save(Record record, TopicMetadata topicMetadata, ProducerMetadata producerMetadata)
{
    record.getData();
    topicMetadata.getName();
    producerMetadata.getId();
}

int TopicHandler::findTopicIndex(TopicMetadata topicMetadata)
{
    topicMetadata.getName();
    return 1;
}

void TopicHandler::subscribe(ConsumerMetadata consumerMetadata, TopicMetadata topicMetadata, Communication *communication)
{
    consumerMetadata.getId();
    topicMetadata.getName();
    if (communication)
    {
    }
}

void TopicHandler::updateConsumers(TopicMetadata topicMetadata)
{
    topicMetadata.getName();
}