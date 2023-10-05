#include "CommunicationFactory.hpp"
#include "StandardOutputLogger.hpp"
#include "RPMessageEndpoint.hpp"
#include "EndpointFactory.hpp"
#include <iostream>
#include <map>

void usage(std::map<std::string, std::string> &idToProcessor)
{
    std::cout << "Usage: ./launchMessage idProcessor" << std::endl;

    std::cout << "ID to Processor Mapping:" << std::endl;
    for (const auto &pair : idToProcessor)
    {
        std::cout << "  " << pair.first << " -> " << pair.second << std::endl;
    }
}

int main(int argc, char *argv[])
{
    char packet_buf[512], packet_buf_read[512], packet_buf_read2[512] = {0};

    std::map<std::string, std::string> idToProcessor = {
        {"2", "R5_0_0"},
        {"3", "R5_0_1"},
        {"4", "R5_1_0"},
        {"5", "R5_1_1"},
        {"9", "M4"}
        // Add more ID-processor mappings as needed
    };

    if (argc != 2)
    {
        usage(idToProcessor);
        return 1;
    }

    int id = std::stoi(argv[1]);

    StandardOutputLogger logger;
    RPMessageEndpoint *sourceEndpoint = static_cast<RPMessageEndpoint *>(EndpointFactory::createEndpoint(CommunicationType::RPMessageLinux));
    sourceEndpoint->setCoreId(1);
    sourceEndpoint->setServiceEndpoint(10);
    Communication *communication = CommunicationFactory::createCommunication(CommunicationType::RPMessageLinux, *sourceEndpoint, logger);

    memset(packet_buf, 0, sizeof(packet_buf));
    sprintf(packet_buf, "You can start!");
    RPMessageEndpoint *destinationEndpoint = static_cast<RPMessageEndpoint *>(EndpointFactory::createEndpoint(CommunicationType::RPMessageLinux));
    destinationEndpoint->setCoreId(id);
    destinationEndpoint->setServiceEndpoint(14);

    logger.log("I want to send the message: %s, with size: %d", packet_buf, sizeof(packet_buf));

    communication->write(packet_buf, strlen(packet_buf), *destinationEndpoint);
    communication->read(packet_buf_read, strlen(packet_buf), *sourceEndpoint);
    logger.log("Message Received: %s", packet_buf_read);

    delete communication;

    return 0;
}
