#ifndef PARTITIONMETADATA_H
#define PARTITIONMETADATA_H

#include "TopicMetadata.hpp"

class PartitionMetadata {
    private:
        int id;
        TopicMetadata topicMetadata;
    public:
        int get_id();
        TopicMetadata getTopicMetadata();
};



#endif