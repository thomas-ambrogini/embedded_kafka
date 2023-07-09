#ifndef STANDARD_OUTPUT_LOGGER_H
#define STANDARD_OUTPUT_LOGGER_H

#include "Logger.hpp"

#ifdef __unix__
#include <iostream>
#endif

class StandardOutputLogger : public Logger
{
public:
    void log(const char *format, ...) const override;
    void logError(const char *errorMessage) const override;
};

#endif
