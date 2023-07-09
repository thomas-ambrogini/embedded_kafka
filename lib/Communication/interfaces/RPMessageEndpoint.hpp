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
    RPMessageEndpoint(uint32_t coreId, u_int16_t endpoint);

    ~RPMessageEndpoint() override;

    void printEndpointInformation(const Logger &logger) override;

    void to_json(json &j) const override;
    void from_json(const json &j) override;

    void setCoreId(uint32_t coreId);
    void setServiceEndpoint(uint16_t serviceEndpoint);
    uint32_t getCoreId() const;
    uint16_t getServiceEndpoint() const;

private:
    uint32_t coreId;
    uint16_t serviceEndpoint;
};

#endif