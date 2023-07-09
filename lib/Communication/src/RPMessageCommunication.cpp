#include "RPMessageCommunication.hpp"

RPMessageCommunication::RPMessageCommunication(const RPMessageEndpoint &ep, const Logger &l) : : Communication(l), endpoint(ep)
{
    endpoint.printEndpointInformation(logger);
    int32_t status;
    RPMessage_CreateParams createParams;

    RPMessage_CreateParams_init(&createParams);
    createParams.localEndPt = endpoint.getServiceEndpoint();
    status = RPMessage_construct(&msgObject, &createParams);

    DebugP_assert(status == SystemP_SUCCESS);
}

RPMessageCommunication::~RPMessageCommunication()
{
}

int RPMessageCommunication::read(char *buffer, size_t bufferSize, Endpoint &source)
{
    uint32_t status;
    uint16_t msgSize, remoteCoreId, remoteCoreServiceEndpoint;

    msgSize = sizeof(msgBuf);

    status = RPMessage_recv(&msgObject,
                            buffer, &msgSize,
                            &remoteCoreId,
                            &remoteCoreServiceEndpoint,
                            SystemP_WAIT_FOREVER);

    DebugP_assert(status == SystemP_SUCCESS);

    try
    {
        dynamic_cast<RPMessageEndpoint &>(source).setCoreId(remoteCoreId);
        dynamic_cast<RPMessageEndpoint &>(source).setServiceEndpoint(remoteCoreServiceEndpoint);
    }
    catch (const std::bad_cast &e)
    {
        logger.logError("[RPMessage read] Bad cast, the source information will not be returned");
    }

    return 1;
}

int RPMessageCommunication::write(const char *message, size_t messageSize, const Endpoint &destination)
{
    try
    {
        const RPMessageEndpoint &rpMessageDestination = dynamic_cast<const RPMessageEndpoint &>(destination);
    }
    catch (const std::bad_cast &e)
    {
        logger.logError("[RPMessage write] Bad cast, the source information will not be returned");
    }

    uint32_t status;
    uint16_t msgSize;

    msgSize = strlen(message) + 1;

    status = RPMessage_send(
        message, msgSize,
        rpMessageDestination.getCoreId(),
        rpMessageDestination.getServiceEndpoint(),
        RPMessage_getLocalEndPt(&msgObject),
        SystemP_WAIT_FOREVER);

    DebugP_assert(status == SystemP_SUCCESS);

    return 1;
}
