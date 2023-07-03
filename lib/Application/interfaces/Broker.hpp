#ifndef BROKER_H
#define BROKER_H

#include "BrokerMetadata.hpp"
#include "TopicHandler.hpp"

class Broker {
    protected:
        BrokerMetadata brokerMetadata;
        TopicHandler topicHandler;

    public:
        virtual void start() = 0;
};



#endif