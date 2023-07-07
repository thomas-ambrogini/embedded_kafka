// Class to be used on the A53 for configuration purposes
// It can read a JSON file and create the configuration that the system manager on other processor can come to ask.

// launch a server waiting for requests where it responds with the information about the cluster (position of the topics)
#ifndef CONFIGURER_H
#define CONFIGURER_H

#include "ClusterMetadata.hpp"
#include "BrokerMetadata.hpp"
#include <fstream>
#include "json.hpp"
#include "CommunicationFactory.hpp"
#include "Communication.hpp"
#include "Logger.hpp"
#include "EndpointFactory.hpp"

using json = nlohmann::json;

class Configurer
{
public:
    Configurer(CommunicationType commType, const Endpoint &endpoint, const Logger &l);

    ~Configurer();

private:
    ClusterMetadata clusterMetadata;
    CommunicationType communicationType;
    const Logger &logger;
    Communication *communication;

    const std::string configFile = "configFile.json";

    void start();
    void retrieveClusterInformation();
    json readJsonFile(const std::string &filename);
};

#endif
