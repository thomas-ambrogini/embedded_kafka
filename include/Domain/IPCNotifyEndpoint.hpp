#ifndef IPCNOTIFYENDPOINT_H
#define IPCNOTIFYENDPOINT_H

#include "Endpoint.hpp"
#include "Processor.hpp"

using nlohmann::json;

class IPCNotifyEndpoint : public Endpoint
{
public:
    IPCNotifyEndpoint(uint32_t coreId, uint16_t clientId, std::function<void(uint32_t, uint16_t, uint32_t, void *)> handler);

    ~IPCNotifyEndpoint() override;

    void printEndpointInformation(const Logger &logger) const override;

    void setCoreId(uint32_t coreId);
    uint32_t getCoreId() const;

    void setClientId(uint16_t clientId);
    uint16_t getClientId() const;

    std::function<void(uint32_t, uint16_t, uint32_t, void *)> &getHandler();
    void setHandler(std::function<void(uint32_t, uint16_t, uint32_t, void *)> handler);

private:
    uint32_t coreId;
    uint16_t clientId;
    std::function<void(uint32_t, uint16_t, uint32_t, void *)> handler_;
};

#endif
