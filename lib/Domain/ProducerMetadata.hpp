#ifndef PRODUCERMETADATA_H
#define PRODUCERMETADATA_H

#include "json.hpp"

using json = nlohmann::json; 

class ProducerMetadata {
    private:
        int id;
    public:

        ProducerMetadata() {}

        ProducerMetadata(int value) : id(value) {}

        int getId() {
            return id;
        }

        void setId(int i) {
            id = i;
        }

        void to_json(json& j) const {
            j = json{{"id", id}};
        }

        void from_json(const json& j) {
            id = j.at("id").get<int>();
        }
};

inline void to_json(nlohmann::json& j, const ProducerMetadata& producerMetadata) {
    producerMetadata.to_json(j);
}




#endif