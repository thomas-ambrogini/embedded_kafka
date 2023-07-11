#include "Configurer.hpp"
#include "StandardOutputLogger.hpp"
#include "CommunicationType.hpp"
#include "json.hpp"
#include "Endpoint.hpp"
#include "ConsumerMetadata.hpp"
#include "LatencyDiagnostic.hpp"

using nlohmann::json;

int main()
{
    StandardOutputLogger logger;
    LatencyDiagnostic latencyDiag(CommunicationType::UDP, logger);

    return 0;
}
