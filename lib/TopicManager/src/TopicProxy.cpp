#include "TopicProxy.hpp"


void TopicProxy::publish(ProducerMetadata producerMetadata, Record record) {
    json request;
    request["operation"] = "publish";
    request["producerMetadata"] = producerMetadata;
    request["topicMetadata"] = topicMetadata;
    request["record"] = record.getData();


    std::string requestString = request.dump();
    std::cout << "Sending the following message:" << requestString << std::endl;

    communication->comm_write(strdup(requestString.c_str()));
}


void TopicProxy::subscribe(ConsumerMetadata consumerMetadata){
    json request;
    request["operation"] = "subscribe";
    request["consumerMetadata"] = consumerMetadata;
    request["topicMetadata"] = topicMetadata;

    std::string requestString = request.dump();
    std::cout << "Sending the following message:" << requestString << std::endl;

    communication->comm_write(strdup(requestString.c_str()));
}

void  TopicProxy::unsubscribe(ConsumerMetadata consumerMetadata){
    json request;
    request["operation"] = "unsubscribe";
    request["consumerMetadata"] = consumerMetadata;
    request["topicMetadata"] = topicMetadata;
    

    std::string requestString = request.dump();
    std::cout << "Sending the following message:" << requestString << std::endl;

    communication->comm_write(strdup(requestString.c_str()));
}

// char*  TopicProxy::poll(ConsumerMetadata consumerMetadata){
//     return nullptr;
// }
