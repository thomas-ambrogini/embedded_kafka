#include "Producer.hpp"
#include "StandardOutputLogger.hpp"
#include "CommunicationType.hpp"
#include <chrono>
#include <thread>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

int main(int argc, char *argv[])
{
    StandardOutputLogger logger;
    CommunicationType commType = CommunicationType::UDP;
    int bootstrapBrokerPort = 12345;
    int messageNumber = 1;

    if (argc == 2)
    {
        try
        {
            bootstrapBrokerPort = std::stoi(argv[1]);
        }
        catch (const std::exception &)
        {
            logger.logError("Invalid format of the boostrap broker port");
        }
    }

    // Seed the random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    BrokerMetadata bootstrapBroker(new UDPEndpoint(bootstrapBrokerPort));
    Producer producer(commType, logger, bootstrapBroker, false);

    std::string topicName = "Measurement";
    TopicMetadata topic(topicName);

    while (true)
    {
        float randomNumber = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX) * 90.0f;
        std::string randomString = std::to_string(randomNumber);

        ProducerRecord producerRecord(topicName, randomString);
        producer.publish(producerRecord);

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}
