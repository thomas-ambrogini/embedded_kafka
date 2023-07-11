#include "Consumer.hpp"
#include "StandardOutputLogger.hpp"
#include "CommunicationType.hpp"
#include <chrono>
#include <thread>

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

    std::string topicName = "Measurements";
    TopicMetadata topic(topicName);

    consumer.subscribe(topic);

    std::this_thread::sleep_for(std::chrono::seconds(5));

    consumer.poll(topic);

    std::this_thread::sleep_for(std::chrono::seconds(2));

    consumer.poll(topic);
    // consumer.unsubscribe(topic);

    return 0;
}
