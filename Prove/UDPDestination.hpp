#ifndef UDPDESTINATION_H
#define UDPDESTINATION_H

#include "Destination.hpp"
#include <cstring>

class UDPDestination : public Destination
{
public:
    char ipAddress[16];
    unsigned int port;

    UDPDestination(const char *ip, unsigned int p);

    void setIpAddress(const char *ip);
    void setPort(unsigned int port);

private:
};

#endif
