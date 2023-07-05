#ifndef UDPSOCKET_COMMUNICATION_H
#define UDPSOCKET_COMMUNICATION_H

#include "Communication.hpp"
#include "Logger.hpp"
#include <netinet/in.h>
#include <cstring>
#include <unistd.h>
#include "Destination.hpp"
#include "UDPDestination.hpp"
#include <arpa/inet.h>

class UDPSocketCommunication : public Communication
{
public:
    UDPSocketCommunication(const char *ip, unsigned int port, Logger *logger);

    int open() override;
    void close() override;
    int read(char *buffer, size_t bufferSize, Destination &source) override;
    int write(const char *message, size_t messageSize, const Destination &destination) override;

private:
    int socketfd;
    struct sockaddr_in serverAddress;
    Logger *logger;
};

#endif
