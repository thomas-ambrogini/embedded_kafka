#include <iostream>
#include "UDPSocketCommunication.hpp"
#include "StandardOutputLogger.hpp"

int main()
{
    // Create a logger
    StandardOutputLogger logger;

    // Create UDPCommunicationInterface object for server
    UDPSocketCommunication server("127.0.0.1", 54321, &logger);

    // Open server connection
    server.open();

    // Receive the message from the client
    char clientBuffer[1024];
    UDPDestination clientSource("", 0);
    if (!server.read(clientBuffer, sizeof(clientBuffer), clientSource))
    {
        logger.logError("Failed to receive message from client");
        return 1;
    }

    std::cout << "Server received message from client: " << clientBuffer << std::endl;
    std::cout << "Received from client: " << clientSource.ipAddress << ":" << clientSource.port << std::endl;

    // Send a response from server to client
    const char *serverMessage = "Hello, client!";
    if (!server.write(serverMessage, std::strlen(serverMessage) + 1, clientSource))
    {
        std::cerr << "Failed to send response from server to client" << std::endl;
        return 1;
    }

    // Close the server connection
    server.close();

    return 0;
}