#ifndef CONSUMER_H
#define CONSUMER_H

class Topic {
    private:
        TopicMetadata metadata;
    public:
        //virtual functions
		virtual char* publish(Record record)  = 0;
        virtual void  subscribe() = 0;
        virtual void  unsubscribe() = 0;
};



#endif