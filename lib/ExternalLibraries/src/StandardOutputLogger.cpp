#include "StandardOutputLogger.hpp"

// void StandardOutputLogger::log(const char *message) const
// {
//     std::cout << message << std::endl;
// }

void StandardOutputLogger::log(const char *format, ...) const
{
    va_list args;
    va_start(args, format);

    vprintf(format, args);
    putchar('\n');

    va_end(args);
}

void StandardOutputLogger::logError(const char *errorMessage) const
{
    std::cerr << "Error: " << errorMessage << std::endl;
}
