#ifndef PRODUCER_H
#define PRODUCER_H

#include "ProducerRecord.hpp"
#include "TopicFactory.hpp"


class Producer {
    private:
        
    public:
		char* publish(ProducerRecord producerRecord);
};



#endif