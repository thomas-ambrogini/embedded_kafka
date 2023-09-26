#include "Consumer.hpp"
#include "StandardOutputLogger.hpp"
#include "CommunicationType.hpp"
#include <chrono>
#include <thread>
#include <iostream>
#include <string>

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
    Consumer consumer(commType, logger, bootstrapBroker);

    std::string topicName = "Prova";
    TopicMetadata topic(topicName);
    consumer.subscribe(topic);

    while(true)
    {
        Record record = consumer.poll(topic);
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << record.getData() << std::endl;
    }

    return 0;
}
