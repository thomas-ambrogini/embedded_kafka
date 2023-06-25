#include "UnixSocketCommunication.hpp"

UnixSocketCommunication::UnixSocketCommunication (char * destination) {
    // Create a socket
    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sockfd == -1) {
        std::cerr << "Failed to create socket." << std::endl;
        return 1;
    }

    // Set up the server address
    struct sockaddr_un serverAddress{};
    serverAddress.sun_family = AF_UNIX;
    strncpy(serverAddress.sun_path, SOCKET_PATH, sizeof(serverAddress.sun_path) - 1);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        std::cerr << "Failed to connect to the server." << std::endl;
        close(sockfd);
        return 1;
    }

}

void UnixSocketCommunication::close() {
    // Close the socket
    close(sockfd);
}

void UnixSocketCommunication::write(char * msg) {
    // Send data to the server
    const char* message = "Hello, server!";
    if (write(sockfd, message, strlen(message)) == -1) {
        std::cerr << "Failed to send data to the server." << std::endl;
    }

}

char* UnixSocketCommunication::read() {
    // Receive response from the server
    char buffer[256];
    ssize_t bytesRead = read(sockfd, buffer, sizeof(buffer) - 1);
    if (bytesRead == -1) {
        std::cerr << "Failed to receive response from the server." << std::endl;
    } else {
        buffer[bytesRead] = '\0';
        std::cout << "Received response: " << buffer << std::endl;
    }
}

void UnixSocketCommunication::ioctl() {
    std::cout << "ioctl" << std::endl;
}