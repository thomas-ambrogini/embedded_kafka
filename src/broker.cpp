#include "BrokerLinux.hpp"
#include <iostream>

 int main(int argc, char* argv[]) {
    if(argc != 2) {
        return -1;
    }

    int brokerPort = atoi(argv[1]);

    std::cout << "The broker will be on port: " << brokerPort << std::endl;
    
    //BROKER
    BrokerMetadata brokerMetadata(new LinuxMetadata(1235));
    BrokerLinux broker(brokerMetadata);

    while(true) {

    }


    return 0;

}