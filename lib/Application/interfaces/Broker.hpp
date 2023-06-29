#ifndef BROKER_H
#define BROKER_H

#include "BrokerMetadata.hpp"

class Broker {
    private:
        BrokerMetadata brokerMetadata;
    public:
        void start();
};



#endif