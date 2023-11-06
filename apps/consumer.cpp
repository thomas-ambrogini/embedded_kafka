#include "Consumer.hpp"
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
              << "'subscribe' to subscribe to a topic" << std::endl
              << "'unsubscribe' to unsubscribe from a topic" << std::endl
              << "'poll' to request a record from a topic" << std::endl;
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
    Consumer consumer(commType, logger, bootstrapBroker, false);

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
        else if (userInput == "subscribe")
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
                consumer.subscribe(topic);
            }
        }
        else if (userInput == "unsubscribe")
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
                consumer.unsubscribe(topic);
            }
        }
        else if (userInput == "poll")
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
                Record record = consumer.poll(topic);
            }
        }
    }

    return 0;
}
