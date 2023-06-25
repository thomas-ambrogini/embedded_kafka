#ifndef SOCKET_COMMUNICATION_H
#define SOCKET_COMMUNICATION_H

#include "Communication.hpp"
#include <iostream>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define MAX_MSG_SIZE          (64u)


const char* SOCKET_PATH = "/tmp/kafka_unix_socket";

class UnixSocketCommunication : public Communication {
    private:
        int sockfd;

    public:
        void close();

        void write(char * msg) override;

        char* read() override;

        void ioctl() override;

};

#endif
