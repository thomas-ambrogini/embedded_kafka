#ifndef BROKERMETADATA_H
#define BROKERMETADATA_H

#include "PlatformDependentMetadata.hpp"

class BrokerMetadata {
    private:
        PlatformDependentMetadata platformMetadata;

    public:
        BrokerMetadata(Processor p, uint16_t endpoint) : platformMetadata(p, endpoint) {};

        PlatformDependentMetadata getPlatformMetadata();
};



#endif