#ifndef TOPICFACTORY_H
#define TOPICFACTORY_H

#include <string.h>
#include "Record.hpp"
#include "TopicMetadata.hpp"
#include "TopicLocal.hpp"
#include "Topic.hpp"
#include "SystemManager.hpp"

class TopicFactory {
    private:
        Topic ** topics = new Topic*[5];
        int topicIndex = 0;
        
        SystemManager systemManager;
        
        bool local = true;

        int topicAlreadyCreated(TopicMetadata topicMetadata);
        TopicLocal * createLocalTopic(TopicMetadata topicMetadata);
    public:
        Topic * getTopic(TopicMetadata topicMetadata);

        void setLocal(bool local);
};



#endif