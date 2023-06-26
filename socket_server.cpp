#include <iostream>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCKET_BUFFER_SIZE          (512)


int main() {
    const char* SOCKET_PATH = "/tmp/kafka_unix_socket1";
    int sockfd,client_sock, msgsock, rval;
    struct sockaddr_un serv_addr, client_addr;
    socklen_t clientlen = sizeof(client_addr);
    char *buf;
    int buflen;
    int nread;

    // Create a socket
    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sockfd == -1) {
        std::cerr << "Failed to create socket." << std::endl;
        return -1;
    }

    const int enable = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
        std::cerr << "Failed to add options." << std::endl;

    serv_addr.sun_family = AF_UNIX;
    strcpy(serv_addr.sun_path, SOCKET_PATH);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(struct sockaddr_un))) {
        std::cerr << "Failed to create the server on bind function" << std::endl;
        return -1;
    }

    listen(sockfd, 10);

    // allocate buffer
    buflen = 1024;
    buf = new char[buflen+1];

      // accept clients
    while ((client_sock = accept(sockfd,(struct sockaddr *)&client_addr,&clientlen)) > 0) {
        std::cout << "Client Accepted" << std::endl;

          // loop to handle all requests
        while (1) {
        
              // read a request
            memset(buf,0,buflen);
            nread = recv(client_sock,buf,buflen,0);
            
            if (nread == 0)
                break;

            // send a response
            send(client_sock, buf, nread, 0);
        }
        close(client_sock);
    }
    
    close(sockfd);


    return -1;
}
