#include "SystemManager.hpp"

SystemManager::SystemManager(const CommunicationType c, const Logger &l) : bootstrapBroker(new UDPEndpoint(12345)), communicationType(c), logger(l)
{
    createCommunication();
    init();
}

SystemManager::SystemManager(const CommunicationType c, const Logger &l, BrokerMetadata b) : bootstrapBroker(b), communicationType(c), logger(l)
{
    createCommunication();
    init();
}

SystemManager::~SystemManager()
{
    delete sourceEndpoint;
    delete communication;
}

void SystemManager::createCommunication()
{
    sourceEndpoint = EndpointFactory::createEndpoint(communicationType);
    communication = CommunicationFactory::createCommunication(communicationType, *sourceEndpoint, logger);
}

void SystemManager::init()
{
    json requestJson;
    requestJson["operation"] = "getClusterInformation";
    std::string requestString = requestJson.dump();

    char response[1024];
    request(requestString.c_str(), requestString.size(), response, sizeof(response));
    logger.log("[System Manager] Received response: %s", response);

    json j = json::parse(response);
    clusterMetadata.from_json(j);
}

int SystemManager::askForID()
{
    json requestJson;
    requestJson["operation"] = "askForID";
    std::string requestString = requestJson.dump();

    char response[1024];
    request(requestString.c_str(), requestString.size(), response, sizeof(response));

    json j = json::parse(response);

    return j["ID"].get<int>();
}

void SystemManager::request(const char *request, size_t requestSize, char *response, size_t responseSize)
{
    logger.log("Sending the following message: %s", request);
    communication->write(request, requestSize + 1, *bootstrapBroker.getEndpoint());

    Endpoint *senderEndpoint = EndpointFactory::createEndpoint(communicationType);

    int resultRead = communication->read(response, responseSize, *senderEndpoint);
    if (resultRead >= 0)
    {
        logger.log("[System Manager] Received response from:");
        senderEndpoint->printEndpointInformation(logger);
    }

    delete senderEndpoint;
}

ClusterMetadata SystemManager::getClusterMetadata() const
{
    return clusterMetadata;
}
