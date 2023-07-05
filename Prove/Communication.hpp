#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <cstddef>
#include "Destination.hpp"

class Communication
{
public:
	virtual int open() = 0;
	virtual void close() = 0;
	virtual int write(const char *msg, const size_t size, const Destination &destination) = 0;
	virtual int read(char *buffer, const size_t size, Destination &source) = 0;
};

#endif
