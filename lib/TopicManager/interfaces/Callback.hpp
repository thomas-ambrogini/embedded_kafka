#ifndef CALLBACK_H
#define CALLBACK_H

#include "TopicMetadata.hpp"
#include <vector>
#include "Communication.hpp"

class Callback {
    private:
        TopicMetadata topicMetadata;
        std::vector<Communication *> channels;
    public:
        Callback(TopicMetadata t) : topicMetadata(t) {}

        TopicMetadata getTopicMetadata() {
            return topicMetadata;
        }

        void addCommunicationChannel(Communication * communication) {
            channels.push_back(communication);
        }

        std::vector<Communication *> getChannels() {
            return channels;
        }

		
};



#endif
