#include "Broker.hpp"
#include "StandardOutputLogger.hpp"

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cout << "Usage: ./broker <integer> <string1> [<string2> ...]\n";
        return 1;
    }

    int brokerPort = std::stoi(argv[1]);

    std::vector<std::string> topicNames;
    for (int i = 2; i < argc; ++i)
    {
        topicNames.push_back(argv[i]);
    }

    std::cout << "Topics in this broker: " << std::endl;
    for (const std::string &name : topicNames)
    {
        std::cout << name << std::endl;
    }

    StandardOutputLogger logger;
    UDPEndpoint endpoint("127.0.0.1", brokerPort);

    Broker broker(CommunicationType::UDP, endpoint, logger, topicNames);

    broker.start();

    return 0;
}
