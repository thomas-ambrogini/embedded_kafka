#ifndef RECORD_H
#define RECORD_H

#include <string>

class Record
{
public:
    Record(const std::string data);

    const std::string &getData() const;

private:
    std::string data;
    char *key;
};

#endif