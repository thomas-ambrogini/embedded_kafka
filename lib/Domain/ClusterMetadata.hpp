#ifndef CLUSTERMETADATA_H
#define CLUSTERMETADATA_H

#include "BrokerMetadata.hpp"
#include "LinuxMetadata.hpp"
#include <iostream>

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

        char * serialize() {
            std::ostringstream oss;

            for (BrokerMetadata brokerMetadata : brokersMetadata) {
                oss << "PlatformMetadata(";
                oss << brokerMetadata.getPlatformMetadata()->serialize() << ",";
                oss << "),";

                oss << "Topics(";
                for (TopicMetadata topicMetadata : brokerMetadata.getTopicsMetadata()) {
                    oss << "Name(" << topicMetadata.getName() << "),";
                }
            }

            std::string str = oss.str();
            char* charPtr = strdup(str.c_str());

            return charPtr;
        }

        

};



#endif