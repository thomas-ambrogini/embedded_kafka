#ifndef CONSUMERMETADATA_H
#define CONSUMERMETADATA_H

#include "json.hpp"

using json = nlohmann::json;

class ConsumerMetadata
{
public:
    ConsumerMetadata() {}

    ConsumerMetadata(int value) : id(value) {}

    int getId()
    {
        return id;
    }

    void setId(int i)
    {
        id = i;
    }

    void to_json(json &j) const
    {
        j = json{{"id", id}};
    }

    void from_json(const json &j)
    {
        id = j.at("id").get<int>();
    }

private:
    int id;
};

inline void to_json(nlohmann::json &j, const ConsumerMetadata &consumerMetadata)
{
    consumerMetadata.to_json(j);
}

#endif