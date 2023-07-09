#include "Consumer.hpp"

Consumer::Consumer(const CommunicationType commType, const Logger &l) : communicationType(commType), logger(l), topicFactory(communicationType, logger)
{
    communicationType;
    askForID();
}

void Consumer::askForID()
{
    consumerMetadata = ConsumerMetadata(1, nullptr);
}

void Consumer::subscribe(TopicMetadata topicMetadata)
{
    Topic *topic = topicFactory.getTopic(topicMetadata);
    topic->subscribe(consumerMetadata);
}

void Consumer::unsubscribe(TopicMetadata topicMetadata)
{
    Topic *topic = topicFactory.getTopic(topicMetadata);
    topic->unsubscribe(consumerMetadata);
}

Record Consumer::poll(TopicMetadata topicMetadata)
{
    Topic *topic = topicFactory.getTopic(topicMetadata);
    return topic->poll(consumerMetadata);
}
