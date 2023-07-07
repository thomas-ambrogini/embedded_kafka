#include "UDPSocketMetadata.hpp"

UDPSocketMetadata::UDPSocketMetadata() : udpEndpoint()
{
}

UDPSocketMetadata::UDPSocketMetadata(const char *ip, int p) : udpEndpoint(ip, p)
{
}

UDPSocketMetadata::UDPSocketMetadata(int p) : udpEndpoint(p)
{
}

UDPSocketMetadata::UDPSocketMetadata(UDPEndpoint e) : udpEndpoint(e)
{
}

UDPSocketMetadata::~UDPSocketMetadata() {}

UDPEndpoint UDPSocketMetadata::getUdpEndpoint() const
{
    return udpEndpoint;
}

void UDPSocketMetadata::to_json(json &j) const
{
    j = json{{"type", "UDPSocket"}, {"endpoint", udpEndpoint}};
}

void UDPSocketMetadata::from_json(const json &j)
{
    UDPEndpoint udpEp;
    udpEp.from_json(j["endpoint"]);
    udpEndpoint = udpEp;
}

void to_json(nlohmann::json &j, const UDPSocketMetadata &obj)
{
    obj.to_json(j);
}