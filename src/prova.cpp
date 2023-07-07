#include "Configurer.hpp"
#include "StandardOutputLogger.hpp"
#include "CommunicationType.hpp"
#include "json.hpp"
#include "Endpoint.hpp"

using nlohmann::json;

int main()
{
    StandardOutputLogger logger;
    ClusterMetadata cluster;

    Endpoint *endpoint = new UDPEndpoint("127.0.0.1", 12345);
    BrokerMetadata broker(endpoint);

    std::string topicName = "Topic 1";
    TopicMetadata topic(topicName);

    broker.addTopicMetadata(topic);

    cluster.addBrokerMetadata(broker);

    json clusterJson;
    cluster.to_json(clusterJson);

    logger.log("cluster JSON info: %s", clusterJson.dump().c_str());

    ClusterMetadata cluster2;
    cluster2.from_json(clusterJson);

    logger.log("Cluster 2 Topic name: %s", cluster2.getBrokersMetadata()[0].getTopicsMetadata()[0].getName().c_str());

    UDPEndpoint udpEndpoint;
    udpEndpoint = *(UDPEndpoint *)cluster2.getBrokersMetadata()[0].getEndpoint();
    logger.log("Cluster 2 Endpoint info: %d", udpEndpoint.getPort());

    return 0;
}