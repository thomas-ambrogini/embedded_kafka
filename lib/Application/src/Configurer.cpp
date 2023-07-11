#ifdef __unix__

#include "Configurer.hpp"

Configurer::Configurer(CommunicationType commType, const Endpoint &endpoint, const Logger &l) : communicationType(commType), logger(l), counter(0)
{
    communication = CommunicationFactory::createCommunication(commType, endpoint, logger);
}

Configurer::Configurer(CommunicationType commType, const Endpoint &endpoint, const Logger &l, const std::string configFile) : communicationType(commType), logger(l), configFile(configFile), counter(0)
{
    communication = CommunicationFactory::createCommunication(commType, endpoint, logger);
}

Configurer::~Configurer()
{
    delete communication;
}

void Configurer::start()
{
    retrieveClusterInformation();

    char clientRequest[1024];
    Endpoint *sourceEndpoint = EndpointFactory::createEndpoint(communicationType);

    while (true)
    {
        if (communication->read(clientRequest, sizeof(clientRequest), *sourceEndpoint) < 0)
        {
            logger.logError("[Configurer] Failed to receive message from client");
            break;
        }
        logger.log("Request received from the client: %s", clientRequest);
        sourceEndpoint->printEndpointInformation(logger);

        handleOperation(clientRequest, sourceEndpoint);
    }

    delete sourceEndpoint;
}

void Configurer::handleOperation(const char *request, Endpoint *sourceEndpoint)
{
    nlohmann::json deserializedRequest = nlohmann::json::parse(request);
    std::string operation = deserializedRequest["operation"];

    logger.log("[Configurer] Operation Received: %s", operation.c_str());

    if (operation == "getClusterInformation")
    {
        json clusterJson;
        clusterMetadata.to_json(clusterJson);

        communication->write(clusterJson.dump().c_str(), clusterJson.dump().size() + 1, *sourceEndpoint);
    }
    else if (operation == "askForID")
    {
        json idJson;
        idJson["ID"] = counter.fetch_add(1);

        communication->write(idJson.dump().c_str(), idJson.dump().size() + 1, *sourceEndpoint);
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

#endif
