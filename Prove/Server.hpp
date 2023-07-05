#ifndef SERVER_H
#define SERVER_H

#include "Communication.hpp"
#include "Logger.hpp"

class Server
{
public:
    virtual void start() = 0;
    virtual void stop() = 0;

protected:
    Logger *logger_;
};

#endif
