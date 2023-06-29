#ifndef CONSUMER_H
#define CONSUMER_H

#include "ConsumerMetadata.hpp"


class Consumer {
    private:
        ConsumerMetadata consumerMetadata;
    public:
        void  subscribe();
        void  unsubscribe();
};



#endif