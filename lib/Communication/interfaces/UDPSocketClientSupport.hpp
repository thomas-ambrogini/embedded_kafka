#ifndef UDPSOCKETCLIENTSUPPORT_COMMUNICATION_H
#define UDPSOCKETCLIENTSUPPORT_COMMUNICATION_H

#include "UDPSocketCommunication.hpp"

class UDPSocketClientSupport {
    private:

    public:
        static Communication * connect(const std::string& ip, int port);
};



#endif