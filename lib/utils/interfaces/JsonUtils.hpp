#ifndef JSONUTILS_H
#define JSONUTILS_H

#include <fstream>
#include "Logger.hpp"
#include "json.hpp"

using json = nlohmann::json;

class JsonUtils
{
public:
    static json readJsonFile(const std::string &filename, const Logger &logger);
    static void writeJsonFile(const std::string &filename, const json jsonData, const Logger &logger);
};

#endif
