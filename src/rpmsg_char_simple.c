#include "CommunicationFactory.hpp"
#include "StandardOutputLogger.hpp"
#include "RPMessageEndpoint.hpp"


int main(int argc, char *argv[])
{
	char packet_buf[512] = { 0 };

	StandardOutputLogger logger;
	RPMessageEndpoint *sourceEndpoint = EndpointFactory::createEndpoint(CommunicationType::RPMessageLinux);
	sourceEndpoint->setCoreId(1);
	sourceEndpoint->setServiceEndpoint(14);
    Communication *communication = CommunicationFactory::createCommunication(CommunicationType::RPMessageLinux, *sourceEndpoint, logger);

	memset(packet_buf, 0, sizeof(packet_buf));
	sprintf(packet_buf, "hello there %d!", i);
	RPMessageEndpoint *destinationEndpoint = EndpointFactory::createEndpoint(CommunicationType::RPMessageLinux);
	destinationEndpoint->setCoreId(2);
	destinationEndpoint->setServiceEndpoint(14);
	communication->commwrite(packet_buf, sizeof(packet_buf), *destinationEndpoint);

	delete communication;

	return 0;
}
