#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

#include "BrokerMetadata.hpp"
#include "ClusterMetadata.hpp"

class SystemManager {
    private:
        BrokerMetadata bootrapBroker;
        ClusterMetadata clusterMetadata;

        void init();


    public:

        // SystemManager() : bootrapBroker(A53_0, 12) {
        //     init();
        // }

        ClusterMetadata getClusterMetadata();
		
};



#endif