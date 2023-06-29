#include "UDPSocketCommunication.hpp"


bool UDPSocketCommunication::comm_write(char * message){
    if (socket_fd == -1) {
        std::cerr << "Socket not initialized" << std::endl;
        return false;
    }

    size_t message_length = std::strlen(message);
    
    // Send the message to the server
    if (sendto(socket_fd, message,message_length, 0,
                (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        std::cerr << "Failed to send data" << std::endl;
        return false;
    }

    return true;
}


char * UDPSocketCommunication::comm_read(){
    if (socket_fd == -1) {
        std::cerr << "Socket not initialized" << std::endl;
        return nullptr;
    }

    // Allocate a buffer for receiving the message
    char* buffer = new char[BUFFER_SIZE];
    std::memset(buffer, 0, BUFFER_SIZE);

    // Receive a message from the server
    struct sockaddr_in client_address;
    socklen_t addr_length = sizeof(client_address);
    ssize_t recv_size = recvfrom(socket_fd, buffer, BUFFER_SIZE - 1, 0,
                                    (struct sockaddr*)&client_address, &addr_length);
    
    if (recv_size == -1) {
        std::cerr << "Failed to receive data" << std::endl;
        delete[] buffer;
        return nullptr;
    }

    // Null-terminate the received message
    buffer[recv_size] = '\0';

    return buffer;
}


void UDPSocketCommunication::comm_close() {
    // Close the socket
    if (socket_fd != -1)
        close(socket_fd);
}

 