#include "Consumer.hpp"

Consumer::Consumer(const CommunicationType commType, const Logger &l) : communicationType(commType), logger(l), topicFactory(communicationType, logger)
{
    askForID();
}

void Consumer::askForID()
{
    consumerMetadata = ConsumerMetadata(1);
}

void Consumer::subscribe(TopicMetadata topicMetadata)
{
    Topic *topic = topicFactory.getTopic(topicMetadata);
    topic->subscribe(consumerMetadata);
}
