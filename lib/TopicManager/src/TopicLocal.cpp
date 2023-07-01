#include "TopicLocal.hpp"

TopicLocal::TopicLocal(TopicMetadata topicMetadata) { 
    this->metadata = topicMetadata;
}


void TopicLocal::publish(Record record) {
    dataBuffer[bufferIndex++] = record.getData();

    for (int i = 0; i < bufferIndex; i++) {
        std::cout << dataBuffer[i] << std::endl;
    }
}

void TopicLocal::subscribe() {

}

void TopicLocal::unsubscribe() {

}

char * TopicLocal::poll() {
    return nullptr;   
}


void TopicLocal::subscribe(ConsumerMetadata consumerMetadata) {
    consumers.push_back(consumerMetadata);
    LocalOffset localOffset(consumerMetadata, 0);
    offsets.push_back(localOffset);
}


void TopicLocal::unsubscribe(ConsumerMetadata consumerMetadata) {
    consumerMetadata.getId();
}



char* TopicLocal::poll(ConsumerMetadata consumerMetadata) {
    int index = findConsumer(consumerMetadata.getId());
    if (index == -1) {
        return nullptr;
    }

    LocalOffset consumerOffset = offsets[index];
    
    if(consumerOffset.getOffset() < bufferIndex) {
        offsets[index].increment();
        return dataBuffer[consumerOffset.getOffset()];
    }

    return nullptr;
}



int TopicLocal::findConsumer(int consumerId) {
    
    for(size_t i = 0; i < consumers.size(); i++) {
        if(consumers[i].getId() == consumerId) {
            return i;
        }
    }

    return -1;
}