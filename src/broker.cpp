#include "Broker.hpp"
#include "StandardOutputLogger.hpp"

int main(int argc, char *argv[])
{
    int brokerPort = 1234;

    if (argc == 2)
    {
        brokerPort = atoi(argv[1]);
    }

    StandardOutputLogger logger;
    UDPEndpoint endpoint("127.0.0.1", brokerPort);

    Broker broker(CommunicationType::UDP, endpoint, logger);

    broker.start();

    return 0;
}
