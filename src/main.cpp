#include "UDPSocketCommunication.hpp"
#include "StandardOutputLogger.hpp"

int main()
{
    // Create a logger
    StandardOutputLogger logger;

    // Create a UDP socket communication object
    UDPSocketCommunication udpCommunication(5000, &logger);

    // Open the communication
    if (udpCommunication.open() == -1)
    {
        logger.logError("Failed to open UDP communication.");
        return 1;
    }

    // Read data
    char buffer[1024];
    int bytesRead = udpCommunication.read(buffer, sizeof(buffer));
    if (bytesRead == -1)
    {
        logger.logError("Failed to read data.");
    }
    else
    {
        logger.log("Received data: ", buffer);
    }

    // Write data
    const char *message = "Hello, server!";
    int bytesWritten = udpCommunication.write(message, strlen(message));
    if (bytesWritten == -1)
    {
        logger.logError("Failed to write data.");
    }
    else
    {
        logger.log("Data sent successfully.");
    }

    // Close the communication
    udpCommunication.close();

    return 0;
}

// #include "UDPSocketClientSupport.hpp"
// #include "UDPSocketServer.hpp"
// #include "Configurer.hpp"
// #include "SystemManager.hpp"
// #include "TopicFactory.hpp"
// #include "Producer.hpp"
// #include "Consumer.hpp"
// #include "BrokerLinux.hpp"

//  int main() {
//     //CONFIGURER
//     Configurer configurer;

//     //GENERAL STUFF
//     const char * topicName = "Topic1";
//     TopicMetadata topicMetadata(strdup(topicName));

//     //BROKER
//     BrokerMetadata brokerMetadata(new LinuxMetadata(1235));
//     BrokerLinux broker(brokerMetadata);

//     // CONSUMER
//     Consumer consumer;
//     consumer.subscribe(topicMetadata);

//     //PRODUCER
//     const char * data = "Hello!";
//     Record record(strdup(data));
//     ProducerRecord producerRecord(topicMetadata, record);
//     Producer producer;
//     producer.publish(producerRecord);

//     std::this_thread::sleep_for(std::chrono::seconds(2));

//     std::cout << "Message received by the consumer: " << consumer.waitForMessage(topicMetadata) << std::endl;

//     std::this_thread::sleep_for(std::chrono::seconds(2));

//     return 0;

// }

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