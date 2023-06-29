#ifndef TOPIC_H
#define TOPIC_H

#include <iostream>

#include "Record.hpp"
#include "TopicMetadata.hpp"
#include "ConsumerMetadata.hpp"

#include <vector>

class Topic {
    protected:
        TopicMetadata metadata;
        std::vector<ConsumerMetadata> consumers;

    public:
        //Virtual Destructor to destroy derived classes
        virtual ~Topic() {}

        //virtual functions
		virtual void  publish(Record record)    = 0;
        virtual void  subscribe()               = 0;
        virtual void  unsubscribe()             = 0;
        virtual char* poll()                    = 0;

        TopicMetadata getTopicMetadata();

};



#endif