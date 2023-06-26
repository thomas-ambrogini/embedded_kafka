#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

#include "BrokerMetadata.hpp"
#include "ClusterMetadata.hpp"

class SystemManager {
    private:
        BrokerMetadata boostrapBroker;
    public:
        void init();
        ClusterMetadata getClusterMetadata();
		
};



#endif