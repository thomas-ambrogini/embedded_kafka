#include "Configurer.hpp"
#include "StandardOutputLogger.hpp"
#include "CommunicationType.hpp"
#include "json.hpp"
#include "Endpoint.hpp"
#include "ConsumerMetadata.hpp"
#include "LatencyDiagnostic.hpp"

using nlohmann::json;

int main()
{
    StandardOutputLogger logger;
    const std::string filename = "../conf/configFile.json";

    std::ifstream file(filename);
    if (!file.is_open())
    {
        logger.logError("Failed to open the config file");
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

    ClusterMetadata clusterMetadata;
    clusterMetadata.from_json(jsonData);

    logger.log("ClusterJson: %s", jsonData.dump().c_str());

    return 0;
}
