#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

class Communication {
    public:
		virtual int comm_read(char * buffer, const size_t size)    = 0;
		virtual int comm_write(const char *msg, const size_t size) = 0;
};

#endif
