#ifndef CONSUMER_H
#define CONSUMER_H

#include "ConsumerMetadata.hpp"
#include "TopicMetadata.hpp"
#include <vector>
#include "TopicFactory.hpp"
#include "Topic.hpp"

class Consumer
{
public:
    Consumer(const CommunicationType communicationType, const Logger &logger);

    void subscribe(TopicMetadata topicMetadata);
    void unsubscribe(TopicMetadata topicMetadata);
    Record poll(TopicMetadata topicMetadata);

    std::vector<TopicMetadata> listSubscribedTopics();

private:
    ConsumerMetadata consumerMetadata;
    std::vector<TopicMetadata> subscribedTopics;
    const Logger &logger;
    TopicFactory topicFactory;

    void askForID();
};

#endif
