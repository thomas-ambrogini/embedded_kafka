#include "UDPSocketServer.hpp"

UDPSocketServer::UDPSocketServer(int port, Logger *logger) : socket_fd(-1)
{
    logger_ = logger;

    socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socket_fd == -1)
    {
        logger_->logError("Failed to create socket");
        return;
    }

    std::memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    int reuse = 1;
    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) == -1)
    {
        logger_->logError("Failed to set socket option");
        closeSocket();
        return;
    }

    if (bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1)
    {
        logger_->logError("Failed to bind socket");
        closeSocket();
        return;
    }
}

UDPSocketServer::~UDPSocketServer()
{
    // Close the socket
    closeSocket();
}

void UDPSocketServer::start()
{
    handleIncomingMessages();
}

void UDPSocketServer::stop()
{
}

void UDPSocketServer::handleIncomingMessages()
{
    char buffer[1024];

    while (true)
    {
        struct sockaddr_in client_address;
        socklen_t addr_length = sizeof(client_address);

        ssize_t recv_size = recvfrom(socket_fd, buffer, sizeof(buffer) - 1, 0,
                                     (struct sockaddr *)&client_address, &addr_length);

        if (recv_size == -1)
        {
            std::cerr << "Failed to receive data" << std::endl;
            continue;
        }

        Communication *communication = new UDPSocketCommunication(socket_fd, client_address, logger_);

        buffer[recv_size] = '\0';

        logger_->log("Received message: %s from: %s:%d", buffer, inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Call the message handler callback
        messageHandler(buffer, communication);
    }
}

void UDPSocketServer::closeSocket()
{
    if (socket_fd != -1)
    {
        close(socket_fd);
        socket_fd = -1;
    }
}

void UDPSocketServer::receiveMessages()
{
    char buffer[1024];

    while (true)
    {
        struct sockaddr_in client_address;
        socklen_t addr_length = sizeof(client_address);

        // Receive a message from the client
        ssize_t recv_size = recvfrom(socket_fd, buffer, sizeof(buffer) - 1, 0,
                                     (struct sockaddr *)&client_address, &addr_length);

        if (recv_size == -1)
        {
            std::cerr << "Failed to receive data" << std::endl;
            continue;
        }

        communication = new UDPSocketCommunication(socket_fd, client_address, logger);

        // Null-terminate the received message
        buffer[recv_size] = '\0';

        // Print the received message and client details
        std::cout << "Received message: " << buffer << " from "
                  << inet_ntoa(client_address.sin_addr) << ":"
                  << ntohs(client_address.sin_port) << std::endl;

        // Call the message handler callback
        messageHandler(buffer, communication);
    }
}