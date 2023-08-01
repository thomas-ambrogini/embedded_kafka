#include "CommunicationFactory.hpp"
#include "StandardOutputLogger.hpp"
#include "RPMessageEndpoint.hpp"
#include "EndpointFactory.hpp"

#include <chrono>

int main(int argc, char *argv[])
{
    uint32_t msg;
    uint16_t msgSize;
    char packet_buf[512], packet_buf_read[512], packet_buf_read2[512] = {0};

    StandardOutputLogger logger;
    RPMessageEndpoint *sourceEndpoint = static_cast<RPMessageEndpoint *>(EndpointFactory::createEndpoint(CommunicationType::RPMessageLinux));
    sourceEndpoint->setCoreId(1);
    sourceEndpoint->setServiceEndpoint(1);
    Communication *communication = CommunicationFactory::createCommunication(CommunicationType::RPMessageLinux, *sourceEndpoint, logger);

    RPMessageEndpoint *destinationEndpoint = static_cast<RPMessageEndpoint *>(EndpointFactory::createEndpoint(CommunicationType::RPMessageLinux));
    destinationEndpoint->setCoreId(1);
    destinationEndpoint->setServiceEndpoint(14);

    communication->write(packet_buf, msgSize, *destinationEndpoint);

    logger.log("i can do this");

    communication->read(packet_buf_read, sizeof(packet_buf), *destinationEndpoint);

    delete communication;
    delete sourceEndpoint;

    return 0;
}
