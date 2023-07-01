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




};


#endif