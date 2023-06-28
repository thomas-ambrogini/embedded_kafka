#ifndef PLATFORMDEPENDENTMETADATA_H
#define PLATFORMDEPENDENTMETADATA_H

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


class PlatformDependentMetadata {
    private:
        Processor processor;
        uint16_t   endpoint;
    public:

        PlatformDependentMetadata(Processor p, u_int16_t e) : processor(p), endpoint(e) {}

        Processor getProcessor() {
            return processor;
        }

        uint16_t getEndpoint() {
            return endpoint;
        }
    
};



#endif