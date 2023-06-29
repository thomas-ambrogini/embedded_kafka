#ifndef PRODUCER_H
#define PRODUCER_H

#include "Record.hpp"
#include "TopicFactory.hpp"


class Producer {
    private:

    public:
		char* publish(Record record);
};



#endif