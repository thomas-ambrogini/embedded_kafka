#include <iostream>
#include <cstring>
#include <unistd.h>
#include "UDPDestination.hpp"
#include "UDPSocketCommunication.hpp"
#include "StandardOutputLogger.hpp"

// Define the Destination classes and UDPCommunicationInterface class here

int main()
{
    StandardOutputLogger logger;

    // Create UDPCommunicationInterface objects for client and server
    UDPSocketCommunication client("127.0.0.1", 12345, &logger);
    UDPSocketCommunication server("127.0.0.1", 54321, &logger);

    // Open client and server connections
    if (!client.open())
    {
        std::cerr << "Failed to open client connection" << std::endl;
        return 1;
    }

    if (!server.open())
    {
        std::cerr << "Failed to open server connection" << std::endl;
        return 1;
    }

    // Create a UDPDestination object for the server
    UDPDestination serverDestination("127.0.0.1", 12345);

    // Send a message from client to server
    const char *clientMessage = "Hello, server!";
    if (!client.write(clientMessage, std::strlen(clientMessage) + 1, serverDestination))
    {
        std::cerr << "Failed to send message from client to server" << std::endl;
        return 1;
    }

    // Receive the message on the server side
    char serverBuffer[1024];
    UDPDestination clientSource("", 0);
    if (!server.read(serverBuffer, sizeof(serverBuffer), clientSource))
    {
        std::cerr << "Failed to receive message on the server side" << std::endl;
        return 1;
    }

    std::cout << "Server received message from client: " << serverBuffer << std::endl;
    std::cout << "Received from client: " << clientSource.ipAddress << ":" << clientSource.port << std::endl;

    // Send a response from server to client
    const char *serverMessage = "Hello, client!";
    if (!server.write(serverMessage, std::strlen(serverMessage) + 1, clientSource))
    {
        std::cerr << "Failed to send message from server to client" << std::endl;
        return 1;
    }

    // Receive the response on the client side
    char clientBuffer[1024];
    UDPDestination serverSource("", 0);
    if (!client.read(clientBuffer, sizeof(clientBuffer), serverSource))
    {
        std::cerr << "Failed to receive message on the client side" << std::endl;
        return 1;
    }

    std::cout << "Client received message from server: " << clientBuffer << std::endl;
    std::cout << "Received from server: " << serverSource.ipAddress << ":" << serverSource.port << std::endl;

    // Close the client and server connections
    client.close();
    server.close();

    return 0;
}
