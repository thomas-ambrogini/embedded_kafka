#include <iostream>
#include "UDPSocketCommunication.hpp"
#include "StandardOutputLogger.hpp"

int main()
{
    // Create a logger
    StandardOutputLogger logger;

    // Create UDPCommunicationInterface object for client
    UDPSocketCommunication client("127.0.0.1", 12345, &logger);

    // Open client connection
    client.open();

    // Create a UDPDestination object for the server
    UDPDestination serverDestination("127.0.0.1", 54321);

    // Send a message from client to server
    const char *clientMessage = "Hello, server!";
    if (client.write(clientMessage, std::strlen(clientMessage) + 1, serverDestination) < 0)
    {
        logger.logError("Failed to send message from client to server");
        return 1;
    }

    // Receive the response from the server
    char responseBuffer[1024];
    UDPDestination serverSource("", 0);
    if (!client.read(responseBuffer, sizeof(responseBuffer), serverSource))
    {
        std::cerr << "Failed to receive response from the server" << std::endl;
        return 1;
    }

    std::cout << "Client received response from server: " << responseBuffer << std::endl;
    std::cout << "Received from server: " << serverSource.ipAddress << ":" << serverSource.port << std::endl;

    // Close the client connection
    client.close();

    return 0;
}
