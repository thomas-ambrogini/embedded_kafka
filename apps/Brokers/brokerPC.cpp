#include "Broker.hpp"
#include "StandardOutputLogger.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    int brokerPort = 0;
    int configurerPort = 12345;

    if (argc == 2)
    {
        brokerPort = std::stoi(argv[1]);
    }

    StandardOutputLogger logger;
    UDPEndpoint endpoint("127.0.0.1", brokerPort);

    Broker broker(CommunicationType::UDP, endpoint, logger, BrokerMetadata(new UDPEndpoint(12345)));
    broker.start();

    return 0;
}