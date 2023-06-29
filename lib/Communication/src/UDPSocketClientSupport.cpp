#include "UDPSocketClientSupport.hpp"


Communication * UDPSocketClientSupport::connect(const std::string& ip, int port) {
    int socket_fd;
    struct sockaddr_in server_address;

    // Create a UDP socket
    socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socket_fd == -1) {
        std::cerr << "Failed to create socket" << std::endl;
        return nullptr;
    }

    // Set up the server address
    std::memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;

    // Convert the IP address from string to binary form
    if (inet_pton(AF_INET, ip.c_str(), &(server_address.sin_addr)) <= 0) {
        std::cerr << "Invalid address or address not supported" << std::endl;
    }

    // Set the server port
    server_address.sin_port = htons(port);

    return new UDPSocketCommunication(socket_fd,server_address);
}
