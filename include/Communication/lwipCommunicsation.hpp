#ifdef SOC_AM64X

#ifndef RPMESSAGE_COMMUNICATION_H
#define RPMESSAGE_COMMUNICATION_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "FreeRTOS.h"
#include "task.h"

#include "Communication.hpp"
#include <kernel/dpl/TaskP.h>
#include <kernel/dpl/ClockP.h>
#include <kernel/dpl/ClockP.h>
#include <networking/enet/utils/include/enet_apputils.h>
#include <networking/enet/utils/include/enet_board.h>
#include "ti_board_config.h"
#include "ti_board_open_close.h"
#include "ti_drivers_open_close.h"
#include "ti_enet_config.h"
#include "ti_enet_open_close.h"
#include "app_cpswconfighandler.h"
#include "app_tcpclient.h"
#include "ti_enet_lwipif.h"
#include <inttypes.h>

/* lwIP core includes */
#include "lwip/opt.h"
#include "lwip/sys.h"
#include "lwip/tcpip.h"
#include "lwip/dhcp.h"

#include "lwipEndpoint.hpp"

class lwipCommunication : public Communication
{
public:
    lwipCommunication(const lwipEndpoint &Endpoint, const Logger &logger);

    ~lwipCommunication();

    int read(char *buffer, size_t bufferSize, Endpoint &source) override;
    int write(const char *message, size_t messageSize, const Endpoint &destination) override;

private:
    // RPMessage_Object msgObject;
    const lwipEndpoint endpoint;
};

#endif
#endif
