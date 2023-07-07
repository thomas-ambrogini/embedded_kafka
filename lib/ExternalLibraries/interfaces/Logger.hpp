#ifndef LOGGER_H
#define LOGGER_H

#include <cstdarg>

class Logger
{
public:
    // virtual void log(const char *message) const = 0;
    virtual void log(const char *format, ...) const = 0;
    virtual void logError(const char *errorMessage) const = 0;
};

#endif
