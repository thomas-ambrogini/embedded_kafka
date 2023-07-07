#ifndef UDPSOCKETMETADATA_H
#define UDPSOCKETMETADATA_H

#include "PlatformDependentMetadata.hpp"
#include "UDPEndpoint.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

class UDPSocketMetadata : public PlatformDependentMetadata
{
public:
    UDPSocketMetadata();
    UDPSocketMetadata(int port);
    UDPSocketMetadata(const char *ipAddress, int port);
    UDPSocketMetadata(UDPEndpoint udpEndpoint);

    ~UDPSocketMetadata();

    UDPEndpoint getUdpEndpoint() const;

    void to_json(json &j) const override;
    void from_json(const json &j) override;

private:
    UDPEndpoint udpEndpoint;
};

void to_json(nlohmann::json &j, const UDPSocketMetadata &obj);

#endif
