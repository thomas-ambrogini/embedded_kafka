#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

class UDPSocketServerSupport {
private:
    int socket_fd;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;

public:
    UDPSocketServerSupport(int port) : socket_fd(-1) {
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

    ~UDPSocketServerSupport() {
        // Close the socket
        closeSocket();
    }

    bool receive(char* buffer, size_t buffer_size) {
        if (socket_fd == -1) {
            std::cerr << "Socket not initialized" << std::endl;
            return false;
        }

        // Receive a message from the client
        socklen_t addr_length = sizeof(client_address);
        ssize_t recv_size = recvfrom(socket_fd, buffer, buffer_size - 1, 0,
                                     (struct sockaddr*)&client_address, &addr_length);
        if (recv_size == -1) {
            std::cerr << "Failed to receive data" << std::endl;
            return false;
        }

        // Null-terminate the received message
        buffer[recv_size] = '\0';

        return true;
    }

    bool send(const char* message) {
        if (socket_fd == -1) {
            std::cerr << "Socket not initialized" << std::endl;
            return false;
        }

        // Send the message to the client
        size_t message_length = std::strlen(message);
        if (sendto(socket_fd, message, message_length, 0,
                   (struct sockaddr*)&client_address, sizeof(client_address)) == -1) {
            std::cerr << "Failed to send data" << std::endl;
            return false;
        }

        return true;
    }

    void closeSocket() {
        if (socket_fd != -1) {
            close(socket_fd);
            socket_fd = -1;
        }
    }
};



int main() {
    UDPSocketServerSupport server(12345);

    // Receive the message on the server side
    const size_t bufferSize = 1024;
    char serverBuffer[bufferSize];
    if (!server.receive(serverBuffer, bufferSize)) {
        std::cerr << "Failed to receive message on the server" << std::endl;
        return 1;
    }

    std::cout << "Server received message: " << serverBuffer << std::endl;
    

    return 0;
}