#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>

class UDPSocketServer {
private:
    int socket_fd;
    struct sockaddr_in server_address;

public:
    UDPSocketServer(int port) : socket_fd(-1) {
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

        // Bind the socket to the server address
        if (bind(socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
            std::cerr << "Failed to bind socket" << std::endl;
            closeSocket();
            return;
        }
    }

    ~UDPSocketServer() {
        // Close the socket
        closeSocket();
    }

    void startListening() {
        std::thread listeningThread(&UDPSocketServer::receiveMessages, this);
        listeningThread.detach();
    }

private:
    void receiveMessages() {
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

            // Process the received message (you can add your logic here)
        }
    }

    void closeSocket() {
        if (socket_fd != -1) {
            close(socket_fd);
            socket_fd = -1;
        }
    }
};


int main() {
    int serverPort = 12345;

    UDPSocketServer server(serverPort);
    server.startListening();

    return 0;
}