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
    TopicFactory(CommunicationType commType, const Logger &logger);
    ~TopicFactory();

    Topic *getTopic(TopicMetadata topicMetadata);

private:
    ClusterMetadata clusterMetadata;
    std::vector<Topic *> topics;
    const CommunicationType communicationType;
    const Logger &logger;

    int findTopic(TopicMetadata topicMetadata);

    void retrieveClusterInformation();
    void createTopics();
};

#endif
