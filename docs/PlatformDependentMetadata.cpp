#include "PlatformDependentMetadata.hpp"

PlatformDependentMetadata::~PlatformDependentMetadata()
{
}

Endpoint PlatformDependentMetadata::getEndpoint() const
{
    return endpoint;
}