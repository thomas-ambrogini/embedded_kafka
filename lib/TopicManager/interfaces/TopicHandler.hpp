#ifndef TOPICHANDLER_H
#define TOPICHANDLER_H

#include "Record.hpp"
#include "TopicMetadata.hpp"
#include "ProducerMetadata.hpp"
#include "Topic.hpp"
#include "Communication.hpp"
#include "Callback.hpp"

class TopicHandler {
    private:
        std::vector<Topic *> topics;
        std::vector<Callback> callbacks;

        void init();

        int findTopicIndex(TopicMetadata topicMetadata);
    public:
        TopicHandler();

        void save(Record record, TopicMetadata topicMetadata, ProducerMetadata producerMetadata);

        void subscribe(ConsumerMetadata consumerMetadata, TopicMetadata topicMetadata, Communication * communication);

        void updateConsumers(TopicMetadata topicMetadata);
        

};



#endif