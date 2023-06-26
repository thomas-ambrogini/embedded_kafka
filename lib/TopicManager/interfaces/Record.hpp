#ifndef RECORD_H
#define RECORD_H

#include "TopicMetadata.hpp"

class Record {
    private:
        TopicMetadata topicMetadata;
        char*         data;
        char*         key;
    public:
        Record(TopicMetadata topicMetadata, char* data, char* key);
		
};



#endif