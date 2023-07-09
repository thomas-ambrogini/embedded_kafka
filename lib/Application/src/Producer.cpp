#include "Producer.hpp"

Producer::Producer(const CommunicationType c, const Logger &l) : logger(l), topicFactory(c, logger)
{
    askForID();
}

void Producer::askForID()
{
    producerMetadata = ProducerMetadata(1);
}

void Producer::publish(ProducerRecord producerRecord)
{
    Topic *topic = topicFactory.getTopic(producerRecord.getTopicMetadata());
    topic->publish(producerMetadata, producerRecord.getRecord());
}
