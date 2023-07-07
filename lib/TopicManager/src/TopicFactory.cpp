#include "TopicFactory.hpp"

TopicFactory::TopicFactory(const CommunicationType commType, const Logger &l) : communicationType(commType), logger(l)
{
    retrieveClusterInformation();
    createTopics();
}

void TopicFactory::retrieveClusterInformation()
{
    SystemManager systemManager(communicationType, logger);
    clusterMetadata = systemManager.getClusterMetadata();
}

void TopicFactory::createTopics()
{
    for (BrokerMetadata brokerMetadata : clusterMetadata.getBrokersMetadata())
    {
        logger.log("Creating the broker instance in the TopicFactory for broker with the following endpoint info:");
        brokerMetadata.getEndpoint()->printEndpointInformation(logger);

        logger.log("In this broker we have the following topics:");

        for (TopicMetadata topicMetadata : brokerMetadata.getTopicsMetadata())
        {
            TopicProxy *topicProxy = new TopicProxy(communicationType, topicMetadata, logger);
            topicProxy->setBrokerMetadata(brokerMetadata);
            logger.log("%s", topicProxy->getTopicMetadata().getName().c_str());
            topics.push_back(topicProxy);
        }
    }
}

TopicFactory::~TopicFactory()
{
}

Topic *TopicFactory::getTopic(TopicMetadata topicMetadata)
{
    int topicIndex = findTopic(topicMetadata);
    logger.log("Index of the topic you are looking for: %d", topicIndex);
    if (topicIndex != -1)
        return topics[topicIndex];
    else
        return nullptr;
}

int TopicFactory::findTopic(TopicMetadata topicMetadata)
{
    for (size_t i = 0; i < topics.size(); i++)
    {
        logger.log("[Find Topic] Comparing: %s and %s", topics[i]->getTopicMetadata().getName().c_str(), topicMetadata.getName().c_str());

        if (topics[i]->getTopicMetadata().getName() == topicMetadata.getName())
        {
            return i;
        }
    }

    return -1;
}
