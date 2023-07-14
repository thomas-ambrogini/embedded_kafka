#ifndef RPMESSAGE_LINUX_COMMUNICATION_H
#define RPMESSAGE_LINUX_COMMUNICATION_H

#include "Communication.hpp"
#include <inttypes.h>
#include "RPMessageEndpoint.hpp"

#include <sys/select.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <stdint.h>
#include <stddef.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <stdbool.h>
#include <semaphore.h>

#include <linux/rpmsg.h>
#include <ti_rpmsg_char.h>

class RPMessageLinuxCommunication : public Communication
{
public:
    RPMessageLinuxCommunication(const RPMessageEndpoint &Endpoint, const Logger &logger);

    ~RPMessageLinuxCommunication();

    int read(char *buffer, size_t bufferSize, Endpoint &source) override;
    int write(const char *message, size_t messageSize, const Endpoint &destination) override;

private:
    const RPMessageEndpoint endpoint;
    rpmsg_char_dev_t *rcdev;

    int send_msg(int fd, const char *msg, int len);
    int recv_msg(int fd, int len, char *reply_msg, int *reply_len);
};

#endif
