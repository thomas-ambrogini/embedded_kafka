#include "Producer.hpp"
#include "StandardOutputLogger.hpp"
#include "CommunicationType.hpp"
#include <chrono>
#include <thread>

int main()
{
    StandardOutputLogger logger;

    Producer producer(CommunicationType::UDP, logger);

    // TOPIC ON WHICH WE WANT TO PUBLISH DATA
    std::string topicName = "Measurements";
    TopicMetadata topic(topicName);

    // RECORD TO PUSH
    Record record("Hello");
    ProducerRecord producerRecord(topicName, record);
    producer.publish(producerRecord);

    Record record2("World");
    ProducerRecord producerRecord2(topicName, record2);
    producer.publish(producerRecord2);

    Record record3("!");
    ProducerRecord producerRecord3(topicName, record3);
    producer.publish(producerRecord3);

    return 0;
}
