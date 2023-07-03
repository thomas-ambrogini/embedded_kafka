#ifndef LINUXMETADATA_H
#define LINUXMETADATA_H

#include "PlatformDependentMetadata.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>



class LinuxMetadata : public PlatformDependentMetadata {
    private:
        int port;
    public:

    LinuxMetadata() {}

    LinuxMetadata(int p) : port(p) {}

    ~LinuxMetadata() {}

    char * serialize() override {
        std::ostringstream oss;
        oss << "Port(" << port << ")";

        std::string str = oss.str();
        char* charPtr = strdup(str.c_str());

        return charPtr;
    }

    int getPort() {
        return port;
    }

    void to_json(json& j) const override {
        j = json{{"type", "LinuxMetadata"}, {"port", port}};
    }

    void from_json(const json& j) override {
        port = j.at("port").get<int>();
    }

};

// inline void to_json(nlohmann::json& j, const LinuxMetadata& obj) {
//   obj.to_json(j);
// }


#endif