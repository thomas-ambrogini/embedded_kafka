#include "Configurer.hpp"

Configurer::Configurer(CommunicationType commType, const Endpoint &endpoint, const Logger &l) : communicationType(commType), logger(l)
{
    communication = CommunicationFactory::createCommunication(commType, endpoint, logger);
    start();
}

Configurer::~Configurer()
{
    delete communication;
}

void Configurer::start()
{
    retrieveClusterInformation();

    while (true)
    {
        char clientBuffer[1024];
        Endpoint *clientSource = EndpointFactory::createEndpoint(communicationType);
        if (communication->read(clientBuffer, sizeof(clientBuffer), *clientSource) < 0)
        {
            logger.logError("Failed to receive message from client");
            break;
        }
        logger.log("Request received from the client: %s", clientBuffer);

        nlohmann::json deserializedRequest = nlohmann::json::parse(clientBuffer);
        std::string operation = deserializedRequest["operation"];

        logger.log("Operation Received: %s", operation.c_str());

        json clusterJson;
        clusterMetadata.to_json(clusterJson);

        logger.log("Information which are sent: %s with size %d", clusterJson.dump().c_str(), clusterJson.dump().size());

        communication->write(clusterJson.dump().c_str(), clusterJson.dump().size() + 1, *clientSource);
        logger.log("Sent back the response");

        delete clientSource;
    }
}

void Configurer::retrieveClusterInformation()
{
    json jsonData = readJsonFile(configFile);

    if (!jsonData.empty())
    {
        clusterMetadata.from_json(jsonData);
    }
    else
    {
        logger.logError("The config JSON file was empty or not found");
    }
}

json Configurer::readJsonFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        logger.logError("Failed to open the config file");
        return json();
    }

    json jsonData;
    try
    {
        file >> jsonData;
    }
    catch (const json::exception &e)
    {
        logger.logError("Failed to parse JSON file");
        return json();
    }

    file.close();

    return jsonData;
}
