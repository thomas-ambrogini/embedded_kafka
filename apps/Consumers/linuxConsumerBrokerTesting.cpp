#include "Consumer.hpp"
#include "StandardOutputLogger.hpp"
#include "CommunicationType.hpp"
#include <chrono>
#include <thread>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <unistd.h>

#define NUM_MESSAGES 100
#define MAX_MSG_SIZE 512

void fillBuffer(char * buffer, int bufferSize) 
{
    memset(buffer, 'c', bufferSize - 1);
    buffer[bufferSize - 1] = '\0';
}

int main(int argc, char *argv[])
{
    const char * fifoName = "/tmp/sync_fifo";

    StandardOutputLogger logger;
    logger.setDebug(false);

    std::ofstream fifo(fifoName);

    CommunicationType commType = CommunicationType::RPMessageLinux;
    int bootstrapBrokerPort = 12345;
    int messageNumber = 1;
    int numMessagesSent = 0;
    char msgBuf[MAX_MSG_SIZE];

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
    Consumer consumer(commType, logger, bootstrapBroker, true);

    std::string topicName = "Testing";
    TopicMetadata topic(topicName);

    consumer.subscribe(topic);

    fifo << "start" << std::endl;

    std::cout << "starting to read messages" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    while (numMessagesSent < NUM_MESSAGES)
    {
        consumer.read(topic);
        numMessagesSent++;
    }

    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Duration of the for loop: " << duration.count() << " microseconds" << std::endl;
    std::cout << "Time for Consumer: " << duration.count()/NUM_MESSAGES << " microseconds" << std::endl;

    return 0;
}
