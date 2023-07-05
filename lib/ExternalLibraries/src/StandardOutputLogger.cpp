#include "StandardOutputLogger.hpp"

void StandardOutputLogger::log(const char *message)
{
    std::cout << message << std::endl;
}

void StandardOutputLogger::log(const char *prefix, const char *message)
{
    std::cout << prefix << message << std::endl;
}

void StandardOutputLogger::logError(const char *errorMessage)
{
    std::cerr << "Error: " << errorMessage << std::endl;
}
