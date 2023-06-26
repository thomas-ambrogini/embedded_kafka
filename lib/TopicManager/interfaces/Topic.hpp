#ifndef TOPIC_H
#define TOPIC_H

#include "Record.hpp"
#include "TopicMetadata.hpp"

class Topic {
    protected:
        TopicMetadata metadata;
    public:
        //virtual functions
		virtual void publish(Record record)  = 0;
        virtual void  subscribe() = 0;
        virtual void  unsubscribe() = 0;

        TopicMetadata getTopicMetadata();
};



#endif