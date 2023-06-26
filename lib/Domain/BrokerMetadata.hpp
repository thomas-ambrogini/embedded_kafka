#ifndef BROKERMETADATA_H
#define BROKERMETADATA_H

#include "PlatformDependentMetadata.hpp"

class BrokerMetadata {
    private:
        int id;
    public:
        int get_id() {
            return id;
        }
};



#endif