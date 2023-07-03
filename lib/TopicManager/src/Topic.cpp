#include "Topic.hpp"

void Topic::publish(ProducerMetadata producerMetadata, Record record) {
    std::cout << "The producer: " << producerMetadata.getId() << " Added the following record: " << record.getData() << std::endl;
    addRecord(record);
}

void Topic::addRecord(Record record) {
    records.push_back(record);
}


void Topic::subscribe(ConsumerMetadata consumerMetadata){
    consumers.push_back(consumerMetadata);
}

void  Topic::unsubscribe(ConsumerMetadata consumerMetadata){
    int consumerIndex = findConsumerIndex(consumerMetadata);
    
    if(consumerIndex != -1) {
        consumers.erase(consumers.begin() + consumerIndex);
    }

    //It's not subscribed
}


int Topic::findConsumerIndex(ConsumerMetadata consumerMetadata) {
    for (size_t i = 0; i < consumers.size(); ++i) {
        if (consumers[i].getId() == consumerMetadata.getId()) {
            return i;
        }
    }

    return -1;
}