#ifndef UDPSOCKET_COMMUNICATION_H
#define UDPSOCKET_COMMUNICATION_H

#include "Communication.hpp"
#include <iostream>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define MAX_MSG_SIZE          (64u)

class UDPSocketCommunication : public Communication {
    private:
        int sockfd;

    public:
        int comm_open();

        void comm_close();

        void comm_write(char * msg) override;

        char* comm_read() override;

        void comm_ioctl() override;

};

#endif
