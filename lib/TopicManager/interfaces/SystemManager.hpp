#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

#include "BrokerMetadata.hpp"
#include "ClusterMetadata.hpp"
#include "Communication.hpp"
#include "UDPSocketClientSupport.hpp"
#include "json.hpp"

using json = nlohmann::json; 


class SystemManager {
    private:
        BrokerMetadata bootstrapBroker;
        ClusterMetadata clusterMetadata;

        void init();

    public:

        SystemManager();

        // SystemManager() : bootrapBroker(A53_0, 12) {
        //     init();
        // }

        ClusterMetadata getClusterMetadata() {
            return clusterMetadata;
        }
		
};



#endif