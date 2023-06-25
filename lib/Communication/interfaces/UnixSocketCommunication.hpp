#ifndef SOCKET_COMMUNICATION_H
#define SOCKET_COMMUNICATION_H

#include "Communication.hpp"

#define MAX_MSG_SIZE          (64u)

//init che crea tutti gli oggetti che mi servono, mettere in una funzione.
//Parte kafka: Comunicazione pub/sub, creazione di comunicazione con topic. Consumer/group.
//implementare le funzioni in un file cpp e definire un file h solamente con l'interfaccia anche per IPC_Communication.
//Creare classi con costruttore specifico e.g; UDPCommunication e una classe come system manager che si occupa di fare le inizializzazioni delle connessioni.

class UnixSocketCommunication : public Communication {
    private:
        char ** util_destination(char * str);

    public:
        UnixSocketCommunication(char * uri);

        ~UnixSocketCommunication() {
            DebugP_log("Destroyed");
        }

        //togliere la close e mettere il distruttore nel system
        void close();

        void write(char * msg) override;

        char* read() override;

        void ioctl() override;

};

#endif
