#include "UDPSocketServer.hpp"


UDPSocketServer::UDPSocketServer(int port) : socket_fd(-1) {
    // Create a UDP socket
    socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socket_fd == -1) {
        std::cerr << "Failed to create socket" << std::endl;
        return;
    }

    // Set up the server address
    std::memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    // Enable address reuse
    int reuse = 1;
    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) == -1) {
        std::cerr << "Failed to set socket option" << std::endl;
        closeSocket();
        return;
    }

    // Bind the socket to the server address
    if (bind(socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        std::cerr << "Failed to bind socket" << std::endl;
        closeSocket();
        return;
    }
}

// void UDPSocketServer::startListening() {
//     std::thread listeningThread(&UDPSocketServer::receiveMessages, this);
//     listeningThread.detach();
// }

void UDPSocketServer::startListening(std::function<void(const char*, const sockaddr_in&)> handler) {
    messageHandler = handler;
    std::thread listeningThread(&UDPSocketServer::receiveMessages, this);
    listeningThread.detach();
}

void UDPSocketServer::closeSocket() {
    if (socket_fd != -1) {
        close(socket_fd);
        socket_fd = -1;
    }
}

UDPSocketServer::~UDPSocketServer() {
    // Close the socket
    closeSocket();
}


void UDPSocketServer::receiveMessages() {
    char buffer[1024];
    
    while (true) {
        struct sockaddr_in client_address;
        socklen_t addr_length = sizeof(client_address);

        // Receive a message from the client
        ssize_t recv_size = recvfrom(socket_fd, buffer, sizeof(buffer) - 1, 0,
                                        (struct sockaddr*)&client_address, &addr_length);
        
        if (recv_size == -1) {
            std::cerr << "Failed to receive data" << std::endl;
            continue;
        }

        // Null-terminate the received message
        buffer[recv_size] = '\0';

        // Print the received message and client details
        std::cout << "Received message: " << buffer << " from "
                    << inet_ntoa(client_address.sin_addr) << ":"
                    << ntohs(client_address.sin_port) << std::endl;

        // Call the message handler callback
        messageHandler(buffer, client_address);


    }
}