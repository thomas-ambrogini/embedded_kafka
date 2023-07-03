#ifndef PRODUCERRECORD_H
#define PRODUCERRECORD_H

#include "Record.hpp"
#include "TopicMetadata.hpp"

class ProducerRecord {
    private:
        TopicMetadata topicMetadata;
        Record record;

    public:
        ProducerRecord(TopicMetadata t, Record r) : topicMetadata(t), record(r) {}


        TopicMetadata getTopicMetadata() {
            return topicMetadata;
        }

        Record getRecord() {
            return record;
        }

		
};



#endif