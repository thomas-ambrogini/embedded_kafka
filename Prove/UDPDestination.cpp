#include "UDPDestination.hpp"

UDPDestination::UDPDestination(const char *ip, unsigned int p) : port(p)
{
    std::strncpy(ipAddress, ip, sizeof(ipAddress));
    ipAddress[sizeof(ipAddress) - 1] = '\0'; // Ensure null-termination
}

void UDPDestination::setIpAddress(const char *ip)
{
    std::strncpy(ipAddress, ip, sizeof(ipAddress));
    ipAddress[sizeof(ipAddress) - 1] = '\0';
}

void UDPDestination::setPort(unsigned int p)
{
    port = p;
}