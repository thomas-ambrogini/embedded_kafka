#include "UnixSocketCommunication.hpp"

int main() {
    UnixSocketCommunication * communication = new UnixSocketCommunication();
    communication->ioctl();

    return 0;
}