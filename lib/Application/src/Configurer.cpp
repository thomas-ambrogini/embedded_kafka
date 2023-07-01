#include "Configurer.hpp"

void Configurer::start() {

    retrieveClusterInformation();

    UDPSocketServer * server = new UDPSocketServer(serverPort);

    server->startListening([](const char* message, Communication* communication) {
        // Custom logic to handle the received message
        // std::cout << "Received message: " << message << " from "
        //           << inet_ntoa(clientAddress.sin_addr) << ":"
        //           << ntohs(clientAddress.sin_port) << std::endl;

        // Add your custom processing or actions here

        // Deserialize the request message from the string
        nlohmann::json deserializedRequest = nlohmann::json::parse(message);

        // Extract the fields from the deserialized request
        std::string operation = deserializedRequest["operation"];

        std::cout << "Operation: " << operation << std::endl;
        std::cout << "Serialization: " << clusterMetadata.serialize() << std::endl;
        char msg[] = clusterMetadata.serialize();
        communication->comm_write(msg);
    });

}


void Configurer::retrieveClusterInformation() {
    json jsonData = readJsonFile(configFile);

    if (!jsonData.empty()) {
        // JSON file read successfully
        // Perform operations on jsonData

        for (const auto& entry : jsonData["brokers"]) {
            int port = entry["port"];
            LinuxMetadata * platformMetadata = new LinuxMetadata(port);
            //LinuxMetadata* linMet = static_cast<LinuxMetadata*>(platformMetadata);

            BrokerMetadata brokerMetadata(platformMetadata);
            
            for (const auto& topicEntry : entry["topics"]) {
                std::string topicNameString = topicEntry["name"];
                TopicMetadata topicMetadata(topicNameString.c_str());
                brokerMetadata.addTopicMetadata(topicMetadata);
            }

            clusterMetadata.addBrokerMetadata(brokerMetadata);
        }

    } else {
        std::cout << "The file was empty or not found" <<std::endl;
    }
}


json readJsonFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return json();
    }

    json jsonData;
    try {
        file >> jsonData;
    } catch (const json::exception& e) {
        std::cerr << "Failed to parse JSON file: " << e.what() << std::endl;
        return json();
    }

    file.close();

    return jsonData;
}
