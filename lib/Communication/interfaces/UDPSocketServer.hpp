#ifndef UDP_SOCKETSERVER_COMMUNICATION_H
#define UDP_SOCKETSERVER_COMMUNICATION_H

#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <functional>
#include "UDPSocketCommunication.hpp"


class UDPSocketServer {
    private:
        int socket_fd;
        struct sockaddr_in server_address;
        std::function<void(const char*, Communication*)> messageHandler;

        UDPSocketCommunication * communication;

        void closeSocket();
        void receiveMessages();

    public:
        UDPSocketServer(int port);

        ~UDPSocketServer();

        void startListening(std::function<void(const char*, Communication*)> handler);

};

#endif
