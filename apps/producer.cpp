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
    Producer producer(commType, logger, bootstrapBroker, false);

    std::string userInput;
    while (true)
    {
        std::cout << "Enter the operation to do (type 'help' for usage, 'exit' to quit): ";
        std::getline(std::cin, userInput);

        if (userInput == "help")
        {
            usage();
        }
        else if (userInput == "exit")
        {
            std::cout << "Exiting the program..." << std::endl;
            break;
        }
        else if (userInput == "publish")
        {
            std::cout << "Enter the name of the topic: ('exit' to go to main menu): ";
            std::getline(std::cin, userInput);

            if (userInput == "exit")
            {
                continue;
            }
            else
            {
                std::string topicName = userInput;
                TopicMetadata topic(topicName);

                std::cout << "Enter the record to publish: ('exit' to go to main menu): ";
                std::getline(std::cin, userInput);

                if (userInput == "exit")
                {
                    continue;
                }
                else
                {
                    std::string recordString = userInput;
                    ProducerRecord producerRecord(topicName, recordString);
                    producer.publish(producerRecord);
                }
            }
        }
    }

    return 0;
}
