#include "Producer.hpp"
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
    // Define the named pipe for synchronization
    const char * fifoName = "/tmp/sync_fifo";

    mkfifo(fifoName, 0666);
    std::ifstream fifo(fifoName);

    StandardOutputLogger logger;
    logger.setDebug(false);

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
    Producer producer(commType, logger, bootstrapBroker, true);

    std::string topicName = "Testing";
    TopicMetadata topic(topicName);
    
    int msgSize = std::stoi(argv[1]);
    int totalNumberOfMessages = std::stoi(argv[2]);
    int delay = std::stoi(argv[3]);

    fillBuffer(msgBuf, msgSize); 
    Record record(msgBuf);
    ProducerRecord producerRecord(topic, record);

    std::string startingMessage;
    fifo >> startingMessage;

    std::cout << startingMessage << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    while (numMessagesSent < totalNumberOfMessages)
    {
        producer.publish(producerRecord);
        numMessagesSent++;
        std::this_thread::sleep_for(std::chrono::microseconds(delay));
    }

    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Duration of the for loop: " << duration.count() << " microseconds" << std::endl;
    std::cout << "Time for Producer (to publish " << numMessagesSent << " messages of size: " << msgSize << " ): " << duration.count()/totalNumberOfMessages << " microseconds" << std::endl;

    return 0;
}
