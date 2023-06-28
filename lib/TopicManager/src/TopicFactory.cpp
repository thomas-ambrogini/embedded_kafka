#include "TopicFactory.hpp"

void TopicFactory::setLocal(bool local) {
    this->local = local;
}

Topic * TopicFactory::getTopic(TopicMetadata topicMetadata) {
    int alreadyCreated = topicAlreadyCreated(topicMetadata);

    if( alreadyCreated == -1) { //Topic doesn't exist
        if (local){
            topics[topicIndex] = createLocalTopic(topicMetadata);
        } else {
            //Need to sync with the system manager
            //Otherwise the topic doesn't exist if we consider a static environment
        }
        return topics[topicIndex++];

    } else { //Topic Already created
        return topics[alreadyCreated];
    }

    return nullptr;
}


int TopicFactory::topicAlreadyCreated(TopicMetadata topicMetadata) {
    for (int i = 0; i < topicIndex; i++) {
        if(strcmp(topics[i]->getTopicMetadata().getName(), topicMetadata.getName()) == 0) {
            return i;
        }
    }

    return -1;
}


TopicLocal * TopicFactory::createLocalTopic(TopicMetadata topicMetadata) {
    return new TopicLocal(topicMetadata);
}