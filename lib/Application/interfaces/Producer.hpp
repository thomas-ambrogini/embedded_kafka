#ifndef PRODUCER_H
#define PRODUCER_H

#include "ProducerRecord.hpp"
#include "TopicFactory.hpp"
#include "ProducerMetadata.hpp"

class Producer {
    private:
        TopicFactory topicFactory;
        ProducerMetadata producerMetadata;

        void askForID();
    public:
        Producer();

        void publish(ProducerRecord producerRecord);
};



#endif