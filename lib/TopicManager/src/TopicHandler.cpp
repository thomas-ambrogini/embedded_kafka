#include "TopicHandler.hpp"

TopicHandler::TopicHandler() {
    init();
}

void TopicHandler::init() {
    const char * topicName = "Topic1";
    TopicMetadata topicMetadata(strdup(topicName));
    Topic * topic = new Topic(topicMetadata);
    topics.push_back(topic);

    Callback callback(topicMetadata);
    callbacks.push_back(callback);
}

void TopicHandler::save(Record record, TopicMetadata topicMetadata, ProducerMetadata producerMetadata) {
    int topicIndex = findTopicIndex(topicMetadata);

    if(topicIndex != -1 ) {
        Topic * topic = topics[topicIndex];
        topic->publish(producerMetadata, record);
    }
}


int TopicHandler::findTopicIndex(TopicMetadata topicMetadata) {
    for (size_t i = 0; i < topics.size(); ++i) {
        if (strcmp(topics[i]->getTopicMetadata().getName(), topicMetadata.getName()) == 0) {
            return i;
        }
    }

    return -1;
}


void TopicHandler::subscribe(ConsumerMetadata consumerMetadata, TopicMetadata topicMetadata, Communication * communication) {
    int topicIndex = findTopicIndex(topicMetadata);

    if(topicIndex != -1 ) {
        Topic * topic = topics[topicIndex];
        topic->subscribe(consumerMetadata);

        callbacks[topicIndex].addCommunicationChannel(communication);
    }
}


void TopicHandler::updateConsumers(TopicMetadata topicMetadata) {
    int topicIndex = findTopicIndex(topicMetadata);

    if(topicIndex != -1 ) {
        Topic * topic = topics[topicIndex];
        Callback callback = callbacks[topicIndex];
        
        for (Communication * comm : callback.getChannels()) {
            comm->comm_write(topic->getLastRecord());
        }
    }
}