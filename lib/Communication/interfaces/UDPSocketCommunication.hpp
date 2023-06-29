#ifndef UDPSOCKET_COMMUNICATION_H
#define UDPSOCKET_COMMUNICATION_H

#include "Communication.hpp"
#include <iostream>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <cstring>
#include <string>
#include <cstring>
#include <arpa/inet.h>

#define BUFFER_SIZE          1024

class UDPSocketCommunication : public Communication {
    private:
        int socket_fd;
        struct sockaddr_in server_address;
    public:

        UDPSocketCommunication(int sock, sockaddr_in sa) : socket_fd(sock), server_address(sa) {}

        void comm_close();

        bool comm_write(char * msg) override;

        char* comm_read() override;

};

#endif
