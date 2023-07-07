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
    SystemManager(const CommunicationType commType, const Logger &l);

    ClusterMetadata getClusterMetadata() const;

private:
    BrokerMetadata bootstrapBroker;
    ClusterMetadata clusterMetadata;
    const Logger &logger;
    const CommunicationType communicationType;

    void init();
};

#endif
