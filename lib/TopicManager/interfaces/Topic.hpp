#ifndef TOPIC_H
#define TOPIC_H

#include <iostream>

#include "Record.hpp"
#include "TopicMetadata.hpp"
#include "ConsumerMetadata.hpp"
#include "ProducerMetadata.hpp"

#include <vector>

class Topic
{
private:
    std::vector<Record> records;
    std::vector<ConsumerMetadata> consumers;

    void addRecord(Record record);
    int findConsumerIndex(ConsumerMetadata consumerMetadata);

protected:
    TopicMetadata topicMetadata;

public:
    Topic(TopicMetadata t) : topicMetadata(t)
    {
    }

    // Virtual Destructor to destroy derived classes
    virtual ~Topic() {}

    // virtual functions
    virtual void publish(ProducerMetadata producerMetadata, Record record);
    virtual void subscribe(ConsumerMetadata consumerMetadata);
    virtual void unsubscribe(ConsumerMetadata consumerMetadata);

    // Do i really want it?
    // virtual char* poll()                                                                 = 0;

    // GETTER
    TopicMetadata getTopicMetadata()
    {
        return topicMetadata;
    }
};

#endif