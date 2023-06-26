#ifndef TOPICFACTORY_H
#define TOPICFACTORY_H

#include <string.h>
#include "Record.hpp"
#include "TopicMetadata.hpp"
#include "Topic.hpp"

class TopicFactory {
    private:
        Topic ** topics = new Topic*[5];
        bool local = true;
        int topicIndex = 0;

        int topicAlreadyCreated(TopicMetadata topicMetadata);
    public:
        Topic * getTopic(TopicMetadata topicMetadata);

        void setLocal(bool local);
};



#endif