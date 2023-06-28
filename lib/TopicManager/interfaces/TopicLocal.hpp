#ifndef TOPICLOCAL_H
#define TOPICLOCAL_H

#include <vector>
#include "Topic.hpp"
#include "ConsumerMetadata.hpp"
#include "LocalOffset.hpp"


class TopicLocal : public Topic {
    private:
        char ** dataBuffer = new char * [10];
        int bufferIndex = 0;
        std::vector<LocalOffset> offsets;


        int findConsumer(int consumerId);

    public:
        ~TopicLocal()  override {
            std::cout << "TopicLocal destructor called." << std::endl;
        }


        TopicLocal(TopicMetadata topicMetadata);

		void   publish(Record record) override;
        void   subscribe()            override;
        void   unsubscribe()          override;
        char*  poll()                 override;


        void   subscribe(ConsumerMetadata consumerMetadata);
        void   unsubscribe(ConsumerMetadata consumerMetadata);
        char*  poll(ConsumerMetadata consumerMetadata);

//        char * poll();

};

#endif