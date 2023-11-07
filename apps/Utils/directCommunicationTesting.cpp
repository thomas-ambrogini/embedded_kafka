#include "CommunicationFactory.hpp"
#include "StandardOutputLogger.hpp"
#include "RPMessageEndpoint.hpp"
#include "EndpointFactory.hpp"
#include <iostream>
#include <map>
#include <cstring>
#include <chrono>
#include <thread>

#define MAX_MESSAGES 100000

void usage(std::map<std::string, std::string> &idToProcessor)
{
    std::cout << "Usage: ./launchMessage idProcessor" << std::endl;

    std::cout << "ID to Processor Mapping:" << std::endl;
    for (const auto &pair : idToProcessor)
    {
        std::cout << "  " << pair.first << " -> " << pair.second << std::endl;
    }
}

void fillBuffer(char * buffer, int bufferSize) 
{
    memset(buffer, 'c', bufferSize);
    buffer[bufferSize] = '\0';
}

int main(int argc, char *argv[])
{
    StandardOutputLogger logger;
    logger.setDebug(false);

    char packet_buf[512], packet_buf_read[512], packet_buf_read2[512] = {0};
    int testingSizes[] = {32, 64, 128, 256, 496};

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

     // Seed the random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int id = std::stoi(argv[1]);

    RPMessageEndpoint *sourceEndpoint = static_cast<RPMessageEndpoint *>(EndpointFactory::createEndpoint(CommunicationType::RPMessageLinux));
    sourceEndpoint->setCoreId(1);
    sourceEndpoint->setServiceEndpoint(14);
    Communication *communication = CommunicationFactory::createCommunication(CommunicationType::RPMessageLinux, *sourceEndpoint, logger);

    RPMessageEndpoint *destinationEndpoint = static_cast<RPMessageEndpoint *>(EndpointFactory::createEndpoint(CommunicationType::RPMessageLinux));
    destinationEndpoint->setCoreId(id);
    destinationEndpoint->setServiceEndpoint(14);

    for (int i = 0; i < sizeof(testingSizes)/sizeof(int); i++) {
        std::cout << "Testing dimension: " << testingSizes[i] << std::endl;

        fillBuffer(packet_buf, testingSizes[i]);

        auto start = std::chrono::high_resolution_clock::now();

        for (int j = 0; j < MAX_MESSAGES; j++) {
            communication->write(packet_buf, strlen(packet_buf), *destinationEndpoint);
            communication->read(packet_buf_read, strlen(packet_buf), *sourceEndpoint);
            //std::this_thread::sleep_for(std::chrono::microseconds(100));

        }
        auto stop = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);    
        std::cout << "Time for RTT with size: (" << testingSizes[i] << ") " <<  duration.count()/MAX_MESSAGES << " microseconds" << std::endl;
    }


    delete communication;

    return 0;
}
