#ifndef PARTITION_H
#define PARTITION_H

#include <vector>
#include "Record.hpp"
#include "PartitionMetadata.hpp"

class Partition {
    private:
        PartitionMetadata partitionMetadata;
        std::vector<Record> records;
    public:

		
};



#endif