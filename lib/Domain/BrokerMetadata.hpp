#ifndef BROKERMETADATA_H
#define BROKERMETADATA_H

#include "PlatformDependentMetadata.hpp"
#include "TopicMetadata.hpp"
#include <vector>
#include "json.hpp"
#include "LinuxMetadata.hpp"

using json = nlohmann::json;

class BrokerMetadata {
    private:
        PlatformDependentMetadata * platformMetadata;
        std::vector<TopicMetadata> topicsMetadata;

    public:
        BrokerMetadata() {}

//        BrokerMetadata(Processor p, uint16_t endpoint) : platformMetadata(p, endpoint) {};
        BrokerMetadata (PlatformDependentMetadata * p) : platformMetadata(p) {
    
        };

        ~BrokerMetadata() {
            
        }

        PlatformDependentMetadata * getPlatformMetadata() {
            return platformMetadata;
        }

        void setPlatformMetadata(PlatformDependentMetadata * p) {
            platformMetadata = p;
        }

        std::vector<TopicMetadata> getTopicsMetadata () {
            return topicsMetadata;
        }

        void addTopicMetadata (TopicMetadata t) {
            topicsMetadata.push_back(t);
        }

        void to_json(json& j) const {
            j = json{{"topicsMetadata", topicsMetadata}};
            if (platformMetadata != nullptr) {
                json polymorphicJson;
                platformMetadata->to_json(polymorphicJson);
                j["platformMetadata"] = polymorphicJson;
            }
        }

        void from_json(const json& j) {
            json polymorphicJson = j.at("platformMetadata");
            std::string type = polymorphicJson.at("type").get<std::string>();

            if (type == "LinuxMetadata") {
                LinuxMetadata* linuxMetadata = new LinuxMetadata();
                linuxMetadata->from_json(polymorphicJson);
                platformMetadata = linuxMetadata;
            }

            for (const auto& item : j.at("topicsMetadata")) {
                TopicMetadata obj;
                obj.from_json(item);
                topicsMetadata.push_back(obj);
            }
        }


};

inline void to_json(json& j, const BrokerMetadata& obj) {
  obj.to_json(j);
}



#endif