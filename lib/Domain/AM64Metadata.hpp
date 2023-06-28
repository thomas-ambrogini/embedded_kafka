#ifndef AM64METADATA_H
#define AM64METADATA_H

#include <inttypes.h>
#include "PlatformDependentMetadata.hpp"

enum CommunicationType{
    RPMessage,
    IPCNotify,
    Ethernet
};

enum Processor {
    M4,
    A53_0,
    A53_1,
    R5_0_0,
    R5_0_1,
    R5_1_0,
    R5_1_1
};


class AM64Metadata : PlatformDependentMetadata {
    private:
        Processor processor;
        uint16_t   endpoint;
    public:

        AM64Metadata(Processor p, uint16_t e) : processor(p), endpoint(e) {}

        ~AM64Metadata() {}

        Processor getProcessor() {
            return processor;
        }

        uint16_t getEndpoint() {
            return endpoint;
        }
};


#endif