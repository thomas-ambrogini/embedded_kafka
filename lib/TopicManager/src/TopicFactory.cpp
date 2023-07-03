#include "TopicFactory.hpp"


TopicFactory::TopicFactory() {
    retrieveClusterInformation();
    createTopics();
}


void TopicFactory::retrieveClusterInformation() {
    SystemManager systemManager;
    clusterMetadata = systemManager.getClusterMetadata();
}

void TopicFactory::createTopics() {
    
    for (BrokerMetadata brokerMetadata : clusterMetadata.getBrokersMetadata()) {

        for (TopicMetadata topicMetadata : brokerMetadata.getTopicsMetadata()) {
            // Perform some operation for each element
            TopicProxy * topicProxy = new TopicProxy(topicMetadata);
            topicProxy->setBrokerMetadata(brokerMetadata);
            topics.push_back(topicProxy);
        }
    }
    
}

TopicFactory::~TopicFactory() {
    
}

Topic * TopicFactory::getTopic(TopicMetadata topicMetadata) {
    int topicIndex = findTopic(topicMetadata);

    if (topicIndex != -1)
        return topics[topicIndex];
    else 
        return nullptr;
}


int TopicFactory::findTopic(TopicMetadata topicMetadata) {
    for (size_t i = 0; i < topics.size(); i++) {
        if(strcmp(topics[i]->getTopicMetadata().getName(), topicMetadata.getName()) == 0) {
            return i;
        }
    }

    return -1;
}


void TopicFactory::setLocal(bool local) {
    this->local = local;
}