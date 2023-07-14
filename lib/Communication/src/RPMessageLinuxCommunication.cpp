#include "RPMessageLinuxCommunication.hpp"

RPMessageLinuxCommunication::RPMessageLinuxCommunication(const RPMessageEndpoint &ep, const Logger &l) : Communication(l), endpoint(ep)
{
    int ret, status, c;

    /* Use auto-detection for SoC */
    ret = rpmsg_char_init(NULL);
    if (ret)
    {
        logger.logError("rpmsg_char_init failed, ret = %d", ret);
    }
}

RPMessageLinuxCommunication::~RPMessageLinuxCommunication()
{
    rpmsg_char_exit();
}

int RPMessageLinuxCommunication::read(char *buffer, size_t bufferSize, Endpoint &source)
{
    int packet_len, ret = 0;

    ret = recv_msg(rcdev->fd, bufferSize, buffer, &packet_len);

    return packet_len;
}

int RPMessageLinuxCommunication::write(const char *message, size_t messageSize, const Endpoint &destination)
{
    const RPMessageEndpoint &rpMessageDestination = static_cast<const RPMessageEndpoint &>(destination);
    char eptdev_name[32] = {0};
    int flags = 0, ret = 0;

    sprintf(eptdev_name, "rpmsg-char-%d-%d", rpMessageDestination.getCoreId(), getpid());

    rcdev = rpmsg_char_open((rproc_id)rpMessageDestination.getCoreId(), NULL, endpoint.getCoreId(), rpMessageDestination.getServiceEndpoint(),
                            eptdev_name, flags);

    ret = send_msg(rcdev->fd, message, messageSize);

    return ret;
}

int RPMessageLinuxCommunication::send_msg(int fd, const char *msg, int len)
{
    int ret = 0;

    ret = ::write(fd, msg, len);
    if (ret < 0)
    {
        perror("Can't write to rpmsg endpt device\n");
        return -1;
    }

    return ret;
}

int RPMessageLinuxCommunication::recv_msg(int fd, int len, char *reply_msg, int *reply_len)
{
    int ret = 0;

    /* Note: len should be max length of response expected */
    ret = ::read(fd, reply_msg, len);
    if (ret < 0)
    {
        perror("Can't read from rpmsg endpt device\n");
        return -1;
    }
    else
    {
        *reply_len = ret;
    }

    return 0;
}