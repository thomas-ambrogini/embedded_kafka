#ifndef TOPICFACTORY_H
#define TOPICFACTORY_H

#include <string.h>
#include "Record.hpp"
#include "TopicMetadata.hpp"
#include "Topic.hpp"
#include "TopicProxy.hpp"
#include "SystemManager.hpp"
#include "ClusterMetadata.hpp"
#include "Communication.hpp"
#include "CommunicationType.hpp"

#include "json.hpp"

using json = nlohmann::json;

class TopicFactory
{
public:
    TopicFactory(CommunicationType communicationType, const Logger &logger);
    TopicFactory(CommunicationType communicationType, const Logger &logger, BrokerMetadata bootstrapBroker);
    ~TopicFactory();

    Topic *getTopic(TopicMetadata topicMetadata);

    int askForID();

private:
    ClusterMetadata clusterMetadata;
    std::vector<Topic *> topics;
    const CommunicationType communicationType;
    const Logger &logger;

    SystemManager systemManager;

    int findTopic(TopicMetadata topicMetadata);

    void retrieveClusterInformation();
    void createTopics();
};

#endif
