#include "Producer.hpp"
#include "StandardOutputLogger.hpp"
#include "CommunicationType.hpp"

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
    Record record("Hello!");

    ProducerRecord producerRecord(topicName, record);

    producer.publish(producerRecord);

    return 0;
}