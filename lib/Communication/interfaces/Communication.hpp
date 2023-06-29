#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>


class Communication {
    public:
        //virtual functions
		virtual char* comm_read()  = 0;
		virtual bool comm_write(char *msg) = 0;

};



#endif