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
#include "UDPSocketClientSupport.hpp"

#include "json.hpp"

using json = nlohmann::json; 

class TopicFactory {
    private:
        ClusterMetadata clusterMetadata;
        std::vector<Topic *> topics;
        
        bool local = true;

        int findTopic(TopicMetadata topicMetadata);

        void retrieveClusterInformation();
        void createTopics();
        
    public:
        TopicFactory();
        ~TopicFactory();

        Topic * getTopic(TopicMetadata topicMetadata);

        void setLocal(bool local);
};



#endif