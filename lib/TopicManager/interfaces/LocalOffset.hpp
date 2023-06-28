#ifndef LOCALOFFSET_H
#define LOCALOFFSET_H

#include "ConsumerMetadata.hpp"

class LocalOffset {
    private:
        ConsumerMetadata consumerMetadata;
        int              offset;
    public:
        LocalOffset(ConsumerMetadata c, int o) : consumerMetadata(c), offset(o) {}

        ConsumerMetadata getConsumerMetadata() {
            return consumerMetadata;
        }

        int getOffset() {
            return offset;
        }

        void increment() {
            offset++;
        }
		
};



#endif