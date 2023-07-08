#include "Configurer.hpp"
#include "StandardOutputLogger.hpp"
#include "CommunicationType.hpp"
#include "json.hpp"
#include "Endpoint.hpp"
#include "ConsumerMetadata.hpp"

using nlohmann::json;

int main()
{
    // Endpoint *endpoint = new UDPEndpoint("127.0.0.1", 12345);
    ConsumerMetadata consumerMetadata(123123, nullptr);

    json consumerJSON;
    consumerMetadata.to_json(consumerJSON);

    std::cout << "CONSUMER JSON: " << consumerJSON.dump() << std::endl;

    return 0;
}
