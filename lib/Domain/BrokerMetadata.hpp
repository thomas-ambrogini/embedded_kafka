#ifndef BROKERMETADATA_H
#define BROKERMETADATA_H

#include "PlatformDependentMetadata.hpp"
#include "TopicMetadata.hpp"
#include <vector>

class BrokerMetadata {
    private:
        PlatformDependentMetadata * platformMetadata;
        std::vector<TopicMetadata> topicsMetadata;

    public:

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

};



#endif