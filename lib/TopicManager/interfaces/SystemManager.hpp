#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

#include "BrokerMetadata.hpp"
#include "CommunicationFactory.hpp"
#include "ClusterMetadata.hpp"
#include "Communication.hpp"
#include "CommunicationType.hpp"
#include "EndpointFactory.hpp"
#include "json.hpp"

using json = nlohmann::json;

class SystemManager
{
public:
    SystemManager(const CommunicationType communicationType, const Logger &logger);
    SystemManager(const CommunicationType communicationType, const Logger &logger, BrokerMetadata boostrapBroker);

    ~SystemManager();

    ClusterMetadata getClusterMetadata() const;

    int askForID();

private:
    BrokerMetadata bootstrapBroker;
    ClusterMetadata clusterMetadata;

    const CommunicationType communicationType;
    const Logger &logger;

    Endpoint *sourceEndpoint;
    Communication *communication;

    void init();
    void createCommunication();

    void request(const char *request, size_t requestSize, char *response, size_t responseSize);
};

#endif
