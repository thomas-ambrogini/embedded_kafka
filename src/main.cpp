#include "UnixSocketCommunication.hpp"


int main() {
    UnixSocketCommunication communication;
    char msg[] = "Hello";

    communication.comm_open_client();
    std::cout << "Sending the following message:" << msg << std::endl;
    communication.comm_write(msg);
    return 0;
}