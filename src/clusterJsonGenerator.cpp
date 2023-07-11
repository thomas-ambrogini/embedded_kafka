#include "Configurer.hpp"
#include "StandardOutputLogger.hpp"
#include "CommunicationType.hpp"
#include "json.hpp"
#include "Endpoint.hpp"
#include "ConsumerMetadata.hpp"

using nlohmann::json;

int main()
{
    ClusterMetadata cluster;
    // Endpoint *endpoint = new UDPEndpoint("127.0.0.1", 12345);

    /*
        Topics we want in the system
    */
    std::string topicName = "Measurements";
    TopicMetadata measures(topicName);

    topicName = "Results";
    TopicMetadata results(topicName);

    /*
        First Broker: used for the publishing of the measured information
    */
    Endpoint *endpoint = new UDPEndpoint("127.0.0.1", 1234);
    BrokerMetadata broker1(endpoint);
    broker1.addTopicMetadata(measures);

    /*
        Second Broker: used for the publishing of results
    */
    endpoint = new UDPEndpoint("127.0.0.1", 1235);
    BrokerMetadata broker2(endpoint);
    broker2.addTopicMetadata(results);

    cluster.addBrokerMetadata(broker1);
    cluster.addBrokerMetadata(broker2);

    json clusterJSON;
    cluster.to_json(clusterJSON);

    std::cout << "Cluster JSON: " << clusterJSON.dump() << std::endl;

    return 0;
}
