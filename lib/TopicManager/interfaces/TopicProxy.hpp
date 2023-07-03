#ifndef TOPICPROXY_H
#define TOPICPROXY_H

#include <vector>
#include "Topic.hpp"
#include "ConsumerMetadata.hpp"
#include "LocalOffset.hpp"
#include "BrokerMetadata.hpp"
#include "Communication.hpp"
#include "UDPSocketClientSupport.hpp"

#include "json.hpp"

using json = nlohmann::json; 

class TopicProxy : public Topic {
    private:
        BrokerMetadata brokerMetadata;
        Communication * communication;

        char ** dataBuffer = new char * [10];
        int bufferIndex = 0;
        std::vector<LocalOffset> offsets;


        int findConsumer(int consumerId);

    public:

        void   publish(ProducerMetadata producerMetadata, Record record) override;
        void   subscribe(ConsumerMetadata consumerMetadata) override;
        void   unsubscribe(ConsumerMetadata consumerMetadata) override;
        //char*  poll(ConsumerMetadata consumerMetadata) override;

        char * waitForMessage() {
            return communication->comm_read();
        }

        ~TopicProxy()  override {
            std::cout << "TopicProxy destructor called." << std::endl;
        }

        TopicProxy(TopicMetadata t) : Topic(t), brokerMetadata(new LinuxMetadata(1235)) {
            topicMetadata = t;
            communication = UDPSocketClientSupport::connect("127.0.0.1", ((LinuxMetadata *)brokerMetadata.getPlatformMetadata())->getPort());
        }

        void setBrokerMetadata(BrokerMetadata b) {
            brokerMetadata = b;
        }

        BrokerMetadata getBrokerMetadata() {
            return brokerMetadata;
        }

};

#endif