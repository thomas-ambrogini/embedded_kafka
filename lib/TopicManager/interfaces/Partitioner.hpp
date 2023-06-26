#ifndef PARTITIONER_H
#define PARTITIONER_H

#include "Record.hpp"
#include "ClusterMetadata.hpp"

class Partitioner {
    private:
        TopicMetadata topicMetadata;
        char*        data;
        char*        key;
    public:
        int get_partition(Record record, ClusterMetadata cluster_metadata);
		
};



#endif