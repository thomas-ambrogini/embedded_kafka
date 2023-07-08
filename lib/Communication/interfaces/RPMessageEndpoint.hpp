#ifndef RPMESSAGEENDPOINT_H
#define RPMESSAGEENDPOINT_H

#include "Endpoint.hpp"
#include "Processor.hpp"
#include "json.hpp"

using nlohmann::json;

class RPMessageEndpoint : public Endpoint
{
public:
    RPMessageEndpoint();
    RPMessageEndpoint(const Processor processor, u_int16_t endpoint);

    ~RPMessageEndpoint() override;

    void printEndpointInformation(const Logger &logger);

    void to_json(json &j) const override;
    void from_json(const json &j) override;

    void setIpAddress(const char *ip);
    void setPort(unsigned int port);
    const char *getIpAddress() const;
    unsigned int getPort() const;

private:
    Processor processor;
    u_int16_t endpoint;
};

#endif
