#ifndef PLATFORMDEPENDENTMETADATA_H
#define PLATFORMDEPENDENTMETADATA_H



class PlatformDependentMetadata {
    
    public:
        virtual ~PlatformDependentMetadata() {}

        virtual char * serialize() = 0;
};



#endif