#include "Consumer.hpp"
#include "Producer.hpp"
#include "StandardOutputLogger.hpp"
#include "CommunicationType.hpp"
#include <chrono>
#include <thread>
#include <iostream>
#include <string>
#include <unistd.h>

void usage() {
    std::cout << "Usage: ./processAndProduce topicNameConsumer topicNameProducer [Configurer port]" << std::endl;
}

int main(int argc, char *argv[])
{
    StandardOutputLogger logger;
    CommunicationType commType = CommunicationType::UDP;
    int bootstrapBrokerPort = 12345;
    std::string topicNameConsumer = "Measurements";
    std::string topicNameProducer = "Results";
    std::string alarmString = "ALARM";

    if (argc == 3)
    {
        topicNameConsumer = argv[1];
        topicNameProducer = argv[2];
    }
    else if (argc == 4)
    {
        topicNameConsumer = argv[1];
        topicNameProducer = argv[2];

        try
        {
            bootstrapBrokerPort = std::stoi(argv[3]);
        }
        catch (const std::exception &)
        {
            logger.logError("Invalid format of the boostrap broker port");
        }
    }

    BrokerMetadata bootstrapBroker(new UDPEndpoint(bootstrapBrokerPort));
    
    //Consumer
    Consumer consumer(commType, logger, bootstrapBroker);
    TopicMetadata topicConsumer(topicNameConsumer);
    consumer.subscribe(topicConsumer);

    //Producer
    Producer producer(commType, logger, bootstrapBroker);
    TopicMetadata topicProducer(topicNameProducer);

    while (true)
    {
        Record record = consumer.poll(topicConsumer);
        if (record.getData() != "NOT VALID")
        {
            std::cout << "Measure read:" << record.getData() << std::endl;
            // float measure = std::stof(record.getData());

            // if(measure < 20) {
            //     ProducerRecord producerRecord(topicNameProducer, alarmString);
            //     producer.publish(producerRecord);
            // }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}
