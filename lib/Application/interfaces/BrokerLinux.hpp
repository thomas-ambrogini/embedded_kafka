#ifndef BROKERLINUX_H
#define BROKERLINUX_H

#include "Broker.hpp"
#include "UDPSocketServer.hpp"
#include "UDPSocketCommunication.hpp"
#include "ProducerMetadata.hpp"

#include "json.hpp"

using json = nlohmann::json; 

class BrokerLinux : public Broker {
    private:
        
    public:
        BrokerLinux(BrokerMetadata b);

        void start();


};



#endif