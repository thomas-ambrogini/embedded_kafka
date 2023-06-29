#ifndef CONSUMER_H
#define CONSUMER_H

#include "ConsumerMetadata.hpp"
#include "TopicMetadata.hpp"
#include <vector>
#include <functional>

//You can put the consumer on a thread at the application level if you want it asynch

class Consumer {

    using MessageCallback = std::function<void(const char *&, const TopicMetadata&)>;

    private:
        ConsumerMetadata consumerMetadata;
        std::vector<TopicMetadata> subscribedTopics;

        MessageCallback callback;

    public:

        void  subscribe(TopicMetadata topicMetadata);
        void  subscribe(TopicMetadata topicMetadata, MessageCallback callback);

        void  unsubscribe(TopicMetadata topicMetadata);

        void setCallback(MessageCallback callback);

        std::vector<TopicMetadata> listSubscribedTopics();


};



#endif