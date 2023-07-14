#include "CommunicationFactory.hpp"
#include "StandardOutputLogger.hpp"
#include "RPMessageEndpoint.hpp"
#include "EndpointFactory.hpp"

int main(int argc, char *argv[])
{
	char packet_buf[512], packet_buf_read[512], packet_buf_read2[512] = {0};

	StandardOutputLogger logger;
	RPMessageEndpoint *sourceEndpoint = static_cast<RPMessageEndpoint *>(EndpointFactory::createEndpoint(CommunicationType::RPMessageLinux));
	sourceEndpoint->setCoreId(1);
	sourceEndpoint->setServiceEndpoint(14);
	Communication *communication = CommunicationFactory::createCommunication(CommunicationType::RPMessageLinux, *sourceEndpoint, logger);

	memset(packet_buf, 0, sizeof(packet_buf));
	sprintf(packet_buf, "hello there %d!", 1);
	RPMessageEndpoint *destinationEndpoint = static_cast<RPMessageEndpoint *>(EndpointFactory::createEndpoint(CommunicationType::RPMessageLinux));
	destinationEndpoint->setCoreId(2);
	destinationEndpoint->setServiceEndpoint(14);

	logger.log("I want to send the message: %s, with size: %d", packet_buf, sizeof(packet_buf));

	communication->write(packet_buf, strlen(packet_buf), *destinationEndpoint);
	communication->read(packet_buf_read, strlen(packet_buf), *sourceEndpoint);
	logger.log("Message Received: %s", packet_buf_read);

	communication->write(packet_buf, strlen(packet_buf), *destinationEndpoint);

	destinationEndpoint->setCoreId(3);
	destinationEndpoint->setServiceEndpoint(14);
	communication->write(packet_buf, strlen(packet_buf), *destinationEndpoint);

	communication->read(packet_buf_read2, strlen(packet_buf), *sourceEndpoint);

	logger.log("Message Received 2: %s", packet_buf_read2);

	communication->read(packet_buf_read2, strlen(packet_buf), *sourceEndpoint);

	logger.log("Message Received 3: %s", packet_buf_read2);

	delete communication;

	return 0;
}
