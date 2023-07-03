#ifndef CLUSTERMETADATA_H
#define CLUSTERMETADATA_H

#include "BrokerMetadata.hpp"
#include "LinuxMetadata.hpp"
#include <iostream>
#include "json.hpp"
#include <string>
#include <vector>

using json = nlohmann::json;


class ClusterMetadata {
    private:
        std::vector<BrokerMetadata> brokersMetadata;

    public:

        std::vector<BrokerMetadata> getBrokersMetadata() {
            return brokersMetadata;
        }

        void addBrokerMetadata(BrokerMetadata b) {
            brokersMetadata.push_back(b);
        }

        void to_json(json& j) const {
            j = json{{"brokersMetadata", brokersMetadata}};
        }

        void from_json(const json& j) {

            for (const auto& item : j.at("brokersMetadata")) {
                BrokerMetadata obj;
                obj.from_json(item);
                brokersMetadata.push_back(obj);
            }
        }

};

inline void to_json(json& j, const ClusterMetadata& obj) {
    obj.to_json(j);
}



#endif