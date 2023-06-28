#ifndef TOPIC_H
#define TOPIC_H

#include <iostream>

#include "Record.hpp"
#include "TopicMetadata.hpp"
#include "ConsumerMetadata.hpp"

class Topic {
    protected:
        TopicMetadata metadata;
        ConsumerMetadata * consumers = new ConsumerMetadata[5];
        int numberOfConsumers = 0;
    public:
        virtual ~Topic() {}

        //virtual functions
		virtual void  publish(Record record)    = 0;
        virtual void  subscribe()               = 0;
        virtual void  unsubscribe()             = 0;
        virtual char* poll()                    = 0;

        TopicMetadata getTopicMetadata();
        void          printConsumerInfo();


};



#endif