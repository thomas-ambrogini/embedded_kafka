#ifdef SOC_AM64X

#ifndef IPCNOTIFY_COMMUNICATION_H
#define IPCNOTIFY_COMMUNICATION_H

#include "Communication.hpp"
#include <kernel/dpl/DebugP.h>
#include <kernel/dpl/ClockP.h>
#include <drivers/ipc_notify.h>
#include "ti_drivers_config.h"
#include "ti_drivers_open_close.h"
#include "ti_board_open_close.h"
#include <inttypes.h>

class IPCNotifyCommunication : public Communication
{
public:
    IPCNotifyCommunication(const IPCNotifyEndpoint &Endpoint, const Logger &logger);

    ~IPCNotifyCommunication();

    int read(char *buffer, size_t bufferSize, Endpoint &source) override;
    int write(const char *message, size_t messageSize, const Endpoint &destination) override;

private:
    const IPCNotifyEndpoint endpoint;
};

#endif
#endif
