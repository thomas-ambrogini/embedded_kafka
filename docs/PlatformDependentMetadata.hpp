#ifndef PLATFORMDEPENDENTMETADATA_H
#define PLATFORMDEPENDENTMETADATA_H

#include "Endpoint.hpp"
#include "json.hpp"

using json = nlohmann::json;

class PlatformDependentMetadata
{
public:
    virtual ~PlatformDependentMetadata();

    virtual Endpoint getEndpoint() const;

    virtual void to_json(json &j) const = 0;
    virtual void from_json(const json &j) = 0;

private:
    Endpoint endpoint;
};

#endif
