#include "Record.hpp"

Record::Record(const std::string d) : data(d)
{
}

const std::string &Record::getData() const
{
    return data;
}
