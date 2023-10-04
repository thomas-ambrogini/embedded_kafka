#include "Configurer.hpp"
#include "StandardOutputLogger.hpp"
#include "CommunicationType.hpp"
#include "json.hpp"
#include "Endpoint.hpp"

using nlohmann::json;

int main()
{
    StandardOutputLogger logger;
    RPMessageEndpoint *sourceEndpoint = static_cast<RPMessageEndpoint *>(EndpointFactory::createEndpoint(CommunicationType::RPMessageLinux));
    sourceEndpoint->setCoreId(1);
    sourceEndpoint->setServiceEndpoint(14);

    Configurer configurer(CommunicationType::RPMessageLinux, *sourceEndpoint, logger, "../conf/configFile.json", false);
    configurer.start();

    delete sourceEndpoint;

    return 0;
}
