#include "BrokerLinux.hpp"

BrokerLinux::BrokerLinux(BrokerMetadata b) {
    brokerMetadata = b;
    start();
}

void BrokerLinux::start() {
    UDPSocketServer * server = new UDPSocketServer(((LinuxMetadata *)brokerMetadata.getPlatformMetadata())->getPort());

    server->startListening([this](const char* message, Communication* communication) {

        // Deserialize the request message from the string
        nlohmann::json deserializedRequest = nlohmann::json::parse(message);

        // Extract the fields from the deserialized request
        std::string operation = deserializedRequest["operation"];

        std::cout << "Operation: " << operation << std::endl;

        if (operation == "publish") {
            json jsonProducerMetadata = deserializedRequest["producerMetadata"];
            ProducerMetadata producerMetadata;
            producerMetadata.from_json(jsonProducerMetadata);

            std::string data = deserializedRequest["record"];
            Record record(strdup(data.c_str()));

            json jsonTopicMetadata = deserializedRequest["topicMetadata"];
            TopicMetadata topicMetadata;
            topicMetadata.from_json(jsonTopicMetadata);

            std::cout << "The producer with ID: " << producerMetadata.getId() << " sent the following record: " << data << " to be published on the topic: " << topicMetadata.getName() << std::endl;

            topicHandler.save(record,topicMetadata, producerMetadata);
            topicHandler.updateConsumers(topicMetadata);
        }
        else if (operation == "subscribe"){
            json jsonConsumerMetadata = deserializedRequest["consumerMetadata"];
            ConsumerMetadata consumerMetadata;
            consumerMetadata.from_json(jsonConsumerMetadata);

            json jsonTopicMetadata = deserializedRequest["topicMetadata"];
            TopicMetadata topicMetadata;
            topicMetadata.from_json(jsonTopicMetadata);

            std::cout << "The consumer with ID: " << consumerMetadata.getId() << " wants to subscribe on the topic: " << topicMetadata.getName() << std::endl;

            topicHandler.subscribe(consumerMetadata, topicMetadata, communication);
        }
        else if (operation == "unsubscribe") {

        }
    });
}