#include "UnixSocketCommunication.hpp"


int main() {
    UnixSocketCommunication communication;
    char msg[] = "Hello";

    communication.comm_open_client();
    std::cout << "Sending the following message:" << msg << std::endl;
    communication.comm_write(msg);
    return 0;
}


// #include <iostream>
// #include "BrokerMetadata.hpp"
// #include "Topic.hpp"
// #include "TopicFactory.hpp"

// int main() {
//     char name [] = "Prova";
    
//     TopicMetadata topicMetadata;
//     topicMetadata.setName(name);

//     TopicFactory topicFactory;
//     topicFactory.setLocal(true);
//     TopicLocal * topic = (TopicLocal *) topicFactory.getTopic(topicMetadata);


//     TopicMetadata t = topic->getTopicMetadata();

//     std::cout << "Name of the Topic:" << t.getName() << std::endl;


//     //Subscriber 1
//     ConsumerMetadata consumerMetadata1(1);
//     topic->subscribe(consumerMetadata1);


//     //Subscriber 2
//     ConsumerMetadata consumerMetadata2(2);
//     topic->subscribe(consumerMetadata2);

//     //Info about the consumers that subscribed to the topic
//     topic->printConsumerInfo();


//     //Producer 1
//     char data [] = "Hello Consumers from Producer 1";
//     char key[] = "Key to partition data";

//     Record recordToPush(data, key);
//     topic->publish(recordToPush);


//     //Producer 1
//     char data2 [] = "Hello Consumers from Producer 2";
//     char key2[] = "Key to partition data";

//     Record recordToPush2(data2, key2);
//     topic->publish(recordToPush2);


//     //Consumer1 Polling for new data
//     char * dataPulled = topic->poll(consumerMetadata1);
//     std::cout << "[Consumer 1] Data polled from the topic: " << dataPulled << std::endl;

//     dataPulled = topic->poll(consumerMetadata1);
//     std::cout << "[Consumer 1] Data polled from the topic (Second call): " << dataPulled << std::endl;


//     //Consumer2 Polling for new data
//     dataPulled = topic->poll(consumerMetadata2);
//     std::cout << "[Consumer 2] Data polled from the topic: " << dataPulled << std::endl;

//     delete topic;


    
// }