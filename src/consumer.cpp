#include "Topic.hpp"
#include "TopicFactory.hpp"

int main() {
    char name [] = "Prova";
    TopicMetadata topicMetadata;
    topicMetadata.setName(name);
    TopicFactory topicFactory;
    topicFactory.setLocal(true);
    topicFactory.getTopic();

    topic.subscribe();
}