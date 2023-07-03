#ifndef PLATFORMDEPENDENTMETADATA_H
#define PLATFORMDEPENDENTMETADATA_H

#include "json.hpp"

using json = nlohmann::json;


class PlatformDependentMetadata {
    
    public:
        virtual ~PlatformDependentMetadata() {}

        virtual char * serialize() = 0;

        virtual void to_json(json& j) const = 0;
        virtual void from_json(const json& j) = 0;
};



#endif