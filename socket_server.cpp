// #include <iostream>
// #include <sys/socket.h>
// #include <sys/un.h>
// #include <unistd.h>

// #define SOCKET_BUFFER_SIZE          (512)

//const char* SOCKET_PATH = "/tmp/kafka_unix_socket1";
// int main() {
//     int sockfd,client_sock, msgsock, rval;
//     struct sockaddr_un serv_addr, client_addr;
//     socklen_t clientlen = sizeof(client_addr);
//     char *buf;
//     int buflen;
//     int nread;

//     // Create a socket
//     sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
//     if (sockfd == -1) {
//         std::cerr << "Failed to create socket." << std::endl;
//         return -1;
//     }

//     const int enable = 1;
//     if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
//         std::cerr << "Failed to add options." << std::endl;

//     serv_addr.sun_family = AF_UNIX;
//     strcpy(serv_addr.sun_path, SOCKET_PATH);
//     if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(struct sockaddr_un))) {
//         std::cerr << "Failed to create the server on bind function" << std::endl;
//         return -1;
//     }

//     listen(sockfd, 10);

//     // allocate buffer
//     buflen = 1024;
//     buf = new char[buflen+1];

//       // accept clients
//     while ((client_sock = accept(sockfd,(struct sockaddr *)&client_addr,&clientlen)) > 0) {
//         std::cout << "Client Accepted" << std::endl;

//           // loop to handle all requests
//         while (1) {
        
//               // read a request
//             memset(buf,0,buflen);
//             nread = recv(client_sock,buf,buflen,0);
            
//             if (nread == 0)
//                 break;

//             // send a response
//             send(client_sock, buf, nread, 0);
//         }
//         close(client_sock);
//     }
    
//     close(sockfd);


//     return -1;
// }




#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

const char* SOCKET_PATH = "/tmp/kafka_unix_socket1";
const int BUFFER_SIZE = 1024;

int main() {
  // Create a socket
  int serverSocket = socket(AF_UNIX, SOCK_STREAM, 0);
  if (serverSocket == -1) {
    std::cerr << "Error creating socket" << std::endl;
    return 1;
  }

  // Set up server address
  struct sockaddr_un serverAddress{};
  serverAddress.sun_family = AF_UNIX;
  strncpy(serverAddress.sun_path, SOCKET_PATH, sizeof(serverAddress.sun_path) - 1);

  const int enable = 1;
  if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
    std::cerr << "Failed to add options." << std::endl;

  // Bind the socket to the server address
  if (bind(serverSocket, reinterpret_cast<struct sockaddr*>(&serverAddress), sizeof(serverAddress)) == -1) {
    std::cerr << "Error binding socket" << std::endl;
    close(serverSocket);
    return 1;
  }

  // Listen for incoming connections
  if (listen(serverSocket, 5) == -1) {
    std::cerr << "Error listening on socket" << std::endl;
    close(serverSocket);
    return 1;
  }

  std::cout << "Server is listening on " << SOCKET_PATH << std::endl;

 while (true) {
    // Accept incoming connections
    struct sockaddr_un clientAddress{};
    socklen_t clientAddressLength = sizeof(clientAddress);
    int clientSocket = accept(serverSocket, reinterpret_cast<struct sockaddr*>(&clientAddress), &clientAddressLength);
    if (clientSocket == -1) {
      std::cerr << "Error accepting connection" << std::endl;
      continue;
    }

    std::cout << "Client connected" << std::endl;

    // Receive and echo client's message
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesRead == -1) {
      std::cerr << "Error receiving data from client" << std::endl;
    } else if (bytesRead == 0) {
      std::cout << "Client disconnected" << std::endl;
    } else {
      std::cout << "Received message from client: " << buffer << std::endl;
      ssize_t bytesSent = send(clientSocket, buffer, bytesRead, 0);
      if (bytesSent == -1) {
        std::cerr << "Error sending data to client" << std::endl;
      }
    }

    // Close the client socket
    close(clientSocket);
  }

  // Close the server socket
  close(serverSocket);

  // Remove the socket file
  unlink(SOCKET_PATH);

  return 0;
}