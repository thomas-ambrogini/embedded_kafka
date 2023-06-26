#ifndef PLATFORMDEPENDENTMETADATA_H
#define PLATFORMDEPENDENTMETADATA_H

enum CommunicationType{
    RPMessage,
    IPCNotify,
    Ethernet
};

enum Processors {
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
        Processors processor;

    public:
    
};



#endif