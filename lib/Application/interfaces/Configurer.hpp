#ifdef __unix__

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
    Configurer(CommunicationType commType, const Endpoint &endpoint, const Logger &l, const std::string configFile);

    ~Configurer();

private:
    ClusterMetadata clusterMetadata;
    CommunicationType communicationType;
    const Logger &logger;
    Communication *communication;

    const std::string configFile = "../conf/configFile.json";

    void start();
    void retrieveClusterInformation();
    json readJsonFile(const std::string &filename);
};

#endif
#endif
