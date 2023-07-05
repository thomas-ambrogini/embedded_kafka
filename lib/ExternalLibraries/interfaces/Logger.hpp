#ifndef LOGGER_H
#define LOGGER_H

class Logger {
    public:
        virtual void log       (const char * message)           = 0;
        virtual void logError  (const char * errorMessage)      = 0;
};

#endif
