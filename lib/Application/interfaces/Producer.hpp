#ifndef PRODUCER_H
#define PRODUCER_H

#include "ProducerRecord.hpp"
#include "TopicFactory.hpp"
#include "ProducerMetadata.hpp"
#include "Logger.hpp"
#include "CommunicationType.hpp"

class Producer
{
public:
    Producer(const CommunicationType communicationType, const Logger &logger);
    Producer(const CommunicationType communicationType, const Logger &logger, BrokerMetadata bootstrapBroker);

    void publish(ProducerRecord producerRecord);

private:
    ProducerMetadata producerMetadata;
    const Logger &logger;
    TopicFactory topicFactory;

    void askForID();
};

#endif
