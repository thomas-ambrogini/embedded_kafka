#include "SystemManager.hpp"

SystemManager::SystemManager(const CommunicationType c, const Logger &l) : bootstrapBroker(new UDPEndpoint(12345)), logger(l), communicationType(c)
{
    init();
}

void SystemManager::init()
{
    Endpoint *sourceEndpoint = EndpointFactory::createEndpoint(communicationType);
    Communication *communication = CommunicationFactory::createCommunication(communicationType, *sourceEndpoint, logger);

    json request;
    request["operation"] = "getClusterInformation";
    std::string requestString = request.dump();

    logger.log("Sending the following message: %s", requestString.c_str());
    communication->write(requestString.c_str(), requestString.size() + 1, *bootstrapBroker.getEndpoint());

    char response[1024];
    Endpoint *senderEndpoint = EndpointFactory::createEndpoint(communicationType);
    int resultRead = communication->read(response, sizeof(response), *senderEndpoint);
    if (resultRead >= 0)
    {
        logger.log("Received response from:");
        senderEndpoint->printEndpointInformation(logger);
        logger.log("Received response: %s", response);
    }

    json j = json::parse(response);
    clusterMetadata.from_json(j);

    delete communication;
    delete sourceEndpoint;
    delete senderEndpoint;
}

ClusterMetadata SystemManager::getClusterMetadata() const
{
    return clusterMetadata;
}
