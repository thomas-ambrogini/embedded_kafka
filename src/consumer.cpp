#include "Consumer.hpp"
#include "StandardOutputLogger.hpp"
#include "CommunicationType.hpp"
#include <chrono>
#include <thread>

int main(int argc, char *argv[])
{
    int brokerPort = 1234;
    CommunicationType commType = CommunicationType::UDP;
    if (argc == 2)
    {
        brokerPort = atoi(argv[1]);
    }

    StandardOutputLogger logger;
    UDPEndpoint endpointBroker("127.0.0.1", brokerPort);

    Consumer consumer(commType, logger);

    std::string topicName = "Topic1";
    TopicMetadata topic(topicName);

    consumer.subscribe(topic);

    std::this_thread::sleep_for(std::chrono::seconds(5));

    consumer.poll(topic);

    std::this_thread::sleep_for(std::chrono::seconds(2));

    consumer.unsubscribe(topic);

    return 0;
}
