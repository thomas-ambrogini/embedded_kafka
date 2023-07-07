#ifndef AM64METADATA_H
#define AM64METADATA_H

#include <inttypes.h>
#include "Processor.hpp"
#include "PlatformDependentMetadata.hpp"

enum CommunicationType
{
    RPMessage,
    IPCNotify,
    Ethernet
};

class AM64Metadata : public PlatformDependentMetadata
{
private:
    Processor processor;
    uint16_t endpoint;

public:
    AM64Metadata(Processor p, uint16_t e) : processor(p), endpoint(e) {}

    ~AM64Metadata() {}

    Processor getProcessor()
    {
        return processor;
    }

    uint16_t getEndpoint()
    {
        return endpoint;
    }
};

#endif