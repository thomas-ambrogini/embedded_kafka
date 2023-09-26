#include "Producer.hpp"
#include "StandardOutputLogger.hpp"
#include "CommunicationType.hpp"
#include <chrono>
#include <thread>
#include <iostream>
#include <string>

void usage()
{
    std::cout << "Usage: Enter one of the following operations: " << std::endl
              << "'exit' to quit the program." << std::endl
              << "'publish' to publish data to a topic" << std::endl;
}

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

    BrokerMetadata bootstrapBroker(new UDPEndpoint(bootstrapBrokerPort));
    Producer producer(commType, logger, bootstrapBroker);

    std::string topicName = "Prova";
    TopicMetadata topic(topicName);


    while (true) {
        std::string message = "Message " + std::to_string(messageNumber);
        ProducerRecord producerRecord(topicName, message);
        producer.publish(producerRecord);
        messageNumber++;

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
