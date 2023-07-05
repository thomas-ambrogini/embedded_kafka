#ifndef STANDARD_OUTPUT_LOGGER_H
#define STANDARD_OUTPUT_LOGGER_H

#include "Logger.hpp"
#include <iostream>

class StandardOutputLogger : public Logger
{
public:
    void log(const char *message) override;
    void log(const char *prefix, const char *message);
    void logError(const char *errorMessage) override;
};

#endif
