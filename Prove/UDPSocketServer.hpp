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
#include "Server.hpp"

class UDPSocketServer : public Server
{
public:
    UDPSocketServer(int port, Logger *logger);

    ~UDPSocketServer();

    void start() override;
    void stop() override;

private:
    int socket_fd;
    struct sockaddr_in server_address;

    std::function<void(const char *, Communication *)> messageHandler;

    void closeSocket();
    void receiveMessages();
    void handleIncomingMessages();
};

#endif
