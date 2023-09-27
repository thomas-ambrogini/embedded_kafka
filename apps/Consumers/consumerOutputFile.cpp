#include "Consumer.hpp"
#include "StandardOutputLogger.hpp"
#include "CommunicationType.hpp"
#include <chrono>
#include <thread>
#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>

int main(int argc, char *argv[])
{
    StandardOutputLogger logger;
    CommunicationType commType = CommunicationType::UDP;
    int bootstrapBrokerPort = 12345;
    std::string topicName = "Prova";

    if (argc == 2)
    {
        topicName = argv[1];
    }
    else if (argc == 3)
    {
        topicName = argv[1];
        try
        {
            bootstrapBrokerPort = std::stoi(argv[2]);
        }
        catch (const std::exception &)
        {
            logger.logError("Invalid format of the boostrap broker port");
        }
    }

    std::string monitorPath = "/home/thomas/embedded_kafka/node_server/monitor/";
    std::string filename = monitorPath + topicName + ".txt";

    BrokerMetadata bootstrapBroker(new UDPEndpoint(bootstrapBrokerPort));
    Consumer consumer(commType, logger, bootstrapBroker);

    TopicMetadata topic(topicName);
    consumer.subscribe(topic);

    std::ofstream outputFile(filename);
    if (!outputFile.is_open())
    {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    while (true)
    {
        Record record = consumer.poll(topic);
        if (record.getData() != "NOT VALID")
        {
            outputFile << record.getData() << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    outputFile.close();

    return 0;
}
