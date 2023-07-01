//Class to be used on the A53 for configuration purposes
//It can read a JSON file and create the configuration that the system manager on other processor can come to ask.


//launch a server waiting for requests where it responds with the information about the cluster (position of the topics)
#ifndef CONFIGURER_H
#define CONFIGURER_H

#include "ClusterMetadata.hpp"
#include "BrokerMetadata.hpp"
#include "UDPSocketServer.hpp"
#include "LinuxMetadata.hpp"


#include <fstream>
#include "json.hpp"


using json = nlohmann::json;

class Configurer {
    private:
        int serverPort;
        ClusterMetadata clusterMetadata;
        std::string configFile = "configFile.json";
        
        void start();
        void retrieveClusterInformation();
    public:
        Configurer(int s = 1234) : serverPort(s) {
            start();
        }

        // Getter method
        int getServerPort() {
            return serverPort;
        }

};

json readJsonFile(const std::string& filename);





#endif