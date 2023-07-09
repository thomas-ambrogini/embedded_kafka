#include "StandardOutputLogger.hpp"

void StandardOutputLogger::log(const char *format, ...) const
{
#ifdef __unix__

    va_list args;
    va_start(args, format);

    vprintf(format, args);
    putchar('\n');

    va_end(args);

#endif
}

void StandardOutputLogger::logError(const char *errorMessage) const
{
#ifdef __unix__

    std::cerr << "Error: " << errorMessage << std::endl;

#endif
}
