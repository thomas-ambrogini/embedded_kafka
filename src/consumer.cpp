#include "Consumer.hpp"
#include "StandardOutputLogger.hpp"
#include "CommunicationType.hpp"

int main(int argc, char *argv[])
{
    int brokerPort = 1234;
    CommunicationType commType = CommunicationType::UDP;
    if (argc == 2)
    {
        brokerPort = atoi(argv[1]);
    }

    StandardOutputLogger logger;
    UDPEndpoint endpointBroker("127.0.0.1", brokerPort);

    Consumer consumer(commType, logger);

    return 0;
}