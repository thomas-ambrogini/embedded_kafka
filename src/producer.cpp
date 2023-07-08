#include "Producer.hpp"
#include "StandardOutputLogger.hpp"
#include "CommunicationType.hpp"
#include <chrono>
#include <thread>

int main(int argc, char *argv[])
{
    int brokerPort = 1234;

    if (argc == 2)
    {
        brokerPort = atoi(argv[1]);
    }

    StandardOutputLogger logger;
    UDPEndpoint endpointBroker("127.0.0.1", brokerPort);

    Producer producer(CommunicationType::UDP, logger);

    // TOPIC ON WHICH WE WANT TO PUBLISH DATA
    std::string topicName = "Topic1";
    TopicMetadata topic(topicName);

    // RECORD TO PUSH
    Record record("Hello");
    ProducerRecord producerRecord(topicName, record);
    producer.publish(producerRecord);

    Record record2("World");
    ProducerRecord producerRecord2(topicName, record2);
    producer.publish(producerRecord2);

    Record record3("!");
    ProducerRecord producerRecord3(topicName, record3);
    producer.publish(producerRecord3);

    return 0;
}
