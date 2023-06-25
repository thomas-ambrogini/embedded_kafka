#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>


class Communication {
    public:
        //virtual functions
		virtual char* read()  = 0;
		virtual void write(char *msg) = 0;
		virtual void ioctl() = 0;
};



#endif