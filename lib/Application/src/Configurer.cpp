#include "Configurer.hpp"

void Configurer::start() {
    json jsonData = readJsonFile(configFile);

    if (!jsonData.empty()) {
        std::cout << "The file was NOT empty" <<std::endl;
        // JSON file read successfully
        // Perform operations on jsonData

        // Example: Accessing values from JSON
        std::string name = jsonData["name"];
        // int age = jsonData["age"];
        // bool isActive = jsonData["isActive"];

        std::cout << "Name found: " << name << std::endl;

        // // Example: Iterating over JSON objects
        // for (const auto& entry : jsonData["items"]) {
        //     std::string itemName = entry["name"];
        //     int itemQuantity = entry["quantity"];
        //     std::cout << "Item: " << itemName << ", Quantity: " << itemQuantity << std::endl;
        // }
    } else {
        std::cout << "The file was empty or not found" <<std::endl;
    }

    UDPSocketServer * server = new UDPSocketServer(serverPort);

    server->startListening([](const char* message, const sockaddr_in& clientAddress) {
        // Custom logic to handle the received message
        std::cout << "Received message: " << message << " from "
                  << inet_ntoa(clientAddress.sin_addr) << ":"
                  << ntohs(clientAddress.sin_port) << std::endl;

        // Add your custom processing or actions here
    });

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