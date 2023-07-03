#include "SystemManager.hpp"


SystemManager::SystemManager() : bootstrapBroker(new LinuxMetadata(1234)) {
    init();
}

void SystemManager::init() {
    Communication * communication = UDPSocketClientSupport::connect("127.0.0.1", ((LinuxMetadata *)bootstrapBroker.getPlatformMetadata())->getPort());

    json request;
    request["operation"] = "getClusterInformation";
    std::string requestString = request.dump();

    std::cout << "Sending the following message:" << requestString << std::endl;
    communication->comm_write(strdup(requestString.c_str()));

    char * response = communication->comm_read();
    std::cout << "Received Reponse: " << response << std::endl;

    json j = json::parse(response);
    clusterMetadata.from_json(j);

}



