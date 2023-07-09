#ifdef SOC_AM64X

#include "TI_DebugLogger.hpp"

void TI_DebugLogger::log(const char *format, ...) const
{
    va_list args;
    va_start(args, format);

    char buffer[256];
    vsnprintf(buffer, sizeof(buffer), format, args);
    strncat(buffer, "\n", sizeof(buffer) - strlen(buffer) - 1); // Append endline character

    va_end(args);

    DebugP_log(buffer);
}

void TI_DebugLogger::logError(const char *errorMessage) const
{
    DebugP_log("%s \r\n", errorMessage);
}

#endif
