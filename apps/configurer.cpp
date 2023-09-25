#include "Configurer.hpp"
#include "TI_DebugLogger.hpp"
#include "StandardOutputLogger.hpp"
#include "CommunicationType.hpp"
#include "json.hpp"
#include "Endpoint.hpp"

using nlohmann::json;

int main(int argc, char *argv[])
{

#ifdef SOC_AM64X
    TI_DebugLogger logger;
#else
    StandardOutputLogger logger;
#endif

    Endpoint *sourceEndpoint = EndpointFactory::createEndpoint(CommunicationType::RPMessage);

    Configurer configurer(CommunicationType::RPMessage, *sourceEndpoint, logger);
    configurer.start();

    delete sourceEndpoint;

    return 0;
}