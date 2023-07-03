#ifndef CONSUMER_H
#define CONSUMER_H

#include "ConsumerMetadata.hpp"
#include "TopicMetadata.hpp"
#include <vector>
#include <functional>
#include "TopicFactory.hpp"
#include "Topic.hpp"

//You can put the consumer on a thread at the application level if you want it asynch

class Consumer {

    using MessageCallback = std::function<void(const char *&, const TopicMetadata&)>;

    private:
        TopicFactory topicFactory;
        ConsumerMetadata consumerMetadata;

        std::vector<TopicMetadata> subscribedTopics;

        MessageCallback callback;

        void askForID();
    public:
        Consumer();

        void  subscribe(TopicMetadata topicMetadata);
        void  subscribe(TopicMetadata topicMetadata, MessageCallback callback);

        void  unsubscribe(TopicMetadata topicMetadata);

        void  setCallback(MessageCallback callback);

        char * waitForMessage(TopicMetadata topicMetadata);

        std::vector<TopicMetadata> listSubscribedTopics();


};



#endif