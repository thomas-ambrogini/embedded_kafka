#include "UDPSocketCommunication.hpp"

UDPSocketCommunication::UDPSocketCommunication(const char *ipAddress, unsigned int port, Logger *l) : logger(l)
{
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    if (inet_aton(ipAddress, &serverAddress.sin_addr) == 0)
    {
        l->logError("Invalid IP address");
    }
}

int UDPSocketCommunication::open()
{
    socketfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socketfd == -1)
    {
        logger->logError("Failed to create socket.");
        return -1;
    }

    if (bind(socketfd, reinterpret_cast<struct sockaddr *>(&serverAddress), sizeof(serverAddress)) == -1)
    {
        logger->logError("Failed to bind socket.");
        ::close(socketfd);
        return -1;
    }

    return 0;
}

void UDPSocketCommunication::close()
{
    if (socketfd != -1)
    {
        ::close(socketfd);
        socketfd = -1;
    }
}

int UDPSocketCommunication::read(char *buffer, size_t bufferSize, Destination &source)
{
    struct sockaddr_in clientAddr;
    socklen_t clientAddrLength = sizeof(clientAddr);

    ssize_t receivedBytes = recvfrom(socketfd, buffer, bufferSize, 0, (struct sockaddr *)&clientAddr, &clientAddrLength);
    if (receivedBytes < 0)
    {
        logger->logError("Failed to receive data");
        return -1;
    }

    // Populate the source information
    char ipAddress[INET_ADDRSTRLEN];
    if (inet_ntop(AF_INET, &(clientAddr.sin_addr), ipAddress, INET_ADDRSTRLEN) == nullptr)
    {
        logger->logError("Failed to get source IP address");
        return -1;
    }

    unsigned int port = ntohs(clientAddr.sin_port);
    ((UDPDestination *)&source)->setIpAddress(ipAddress);
    ((UDPDestination *)&source)->setPort(port);

    return receivedBytes;
}

int UDPSocketCommunication::write(const char *message, size_t messageSize, const Destination &destination)
{
    const UDPDestination *udpDestination = dynamic_cast<const UDPDestination *>(&destination);
    if (!udpDestination)
    {
        logger->logError("Invalid destination type");
        return -1;
    }

    struct sockaddr_in destAddr;
    memset(&destAddr, 0, sizeof(destAddr));
    destAddr.sin_family = AF_INET;
    destAddr.sin_port = htons(udpDestination->port);
    if (inet_aton(udpDestination->ipAddress, &destAddr.sin_addr) == 0)
    {
        logger->logError("Invalid destination address");
        return -1;
    }

    ssize_t sentBytes = sendto(socketfd, message, messageSize, 0, (struct sockaddr *)&destAddr, sizeof(destAddr));
    if (sentBytes < 0)
    {
        logger->logError("Failed to write the message.");
        return -1;
    }

    return sentBytes;
}
