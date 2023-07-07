#include "Configurer.hpp"
#include "StandardOutputLogger.hpp"
#include "CommunicationType.hpp"
#include "json.hpp"
#include "Endpoint.hpp"

using nlohmann::json;

int main(int argc, char *argv[])
{
    int configurerPort = 12345;

    if (argc == 2)
    {
        configurerPort = atoi(argv[1]);
    }

    StandardOutputLogger logger;
    UDPEndpoint endpointConfigurer("127.0.0.1", configurerPort);

    Configurer configurer(CommunicationType::UDP, endpointConfigurer, logger);

    return 0;
}