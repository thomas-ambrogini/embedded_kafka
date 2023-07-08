#include "Topic.hpp"

Topic::Topic(const TopicMetadata t, const Logger &l) : topicMetadata(t), logger(l)
{
}

Topic::~Topic()
{
    logger.log("Base destructor of Topic called");
}

const TopicMetadata Topic::getTopicMetadata() const
{
    return topicMetadata;
}
