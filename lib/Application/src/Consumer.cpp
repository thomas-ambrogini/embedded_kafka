#include "Consumer.hpp"

Consumer::Consumer() {
    //We could ask for an ID in here

    //Maybe the ID could be given the first time you send a message?
    askForID();
}

void Consumer::askForID() {
    consumerMetadata = ConsumerMetadata(1);
}

void Consumer::subscribe(TopicMetadata topicMetadata) {
    Topic * topic = topicFactory.getTopic(topicMetadata);
    topic->subscribe(consumerMetadata);
}

char * Consumer::waitForMessage(TopicMetadata topicMetadata) {
    Topic * topic = topicFactory.getTopic(topicMetadata);
    return ((TopicProxy*)topic)->waitForMessage();
}