#ifndef SOCKET_COMMUNICATION_H
#define SOCKET_COMMUNICATION_H

#include "Communication.hpp"
#include <iostream>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define MAX_MSG_SIZE          (64u)

class UnixSocketCommunication : public Communication {
    private:
        int sockfd;
        const char* SOCKET_PATH = "/tmp/kafka_unix_socket1";


    public:
        int comm_open_client();

        void comm_close();

        void comm_write(char * msg) override;

        char* comm_read() override;

        void comm_ioctl() override;

};

#endif
