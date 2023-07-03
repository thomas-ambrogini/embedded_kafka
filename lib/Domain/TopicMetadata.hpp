#ifndef TOPICMETADATA_H
#define TOPICMETADATA_H

#include "json.hpp"

using json = nlohmann::json;


class TopicMetadata {
    private:
        char* name;
    public:
        TopicMetadata () {}
        TopicMetadata (char * n) : name(n) {}

        char * getName() {
            return name;
        }

        void to_json(json& j) const {
            j = json{{"name", name}};
        }

        void from_json(const json& j) {
            name = strdup(j.at("name").get<std::string>().c_str());
        }

};

inline void to_json(nlohmann::json& j, const TopicMetadata& obj) {
  obj.to_json(j);
}



#endif