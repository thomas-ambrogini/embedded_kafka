#ifndef STANDARD_OUTPUT_LOGGER_H
#define STANDARD_OUTPUT_LOGGER_H

#include "Logger.hpp"
#include <iostream>
#include <cstdarg>

class StandardOutputLogger : public Logger
{
public:
    void log(const char *message) override;
    void log(const char *format, ...) override;
    void logError(const char *errorMessage) override;
};

#endif
