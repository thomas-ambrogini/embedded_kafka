#ifndef TOPICLOCAL_H
#define TOPICLOCAL_H

#include "Topic.hpp"


class TopicLocal : public Topic {
    private:
        char ** dataBuffer;
    public:
        TopicLocal(TopicMetadata topicMetadata);

		void   publish(Record record);
        void   subscribe();
        void   unsubscribe();
        char * poll();

};

#endif