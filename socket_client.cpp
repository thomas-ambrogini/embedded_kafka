#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

const char* SOCKET_PATH = "/tmp/kafka_unix_socket1";
const int BUFFER_SIZE = 1024;

int main() {
  // Create a socket
  int clientSocket = socket(AF_UNIX, SOCK_STREAM, 0);
  if (clientSocket == -1) {
    std::cerr << "Error creating socket" << std::endl;
    return 1;
  }

  // Set up server address
  struct sockaddr_un serverAddress{};
  serverAddress.sun_family = AF_UNIX;
  strncpy(serverAddress.sun_path, SOCKET_PATH, sizeof(serverAddress.sun_path) - 1);

  // Connect to the server
  if (connect(clientSocket, reinterpret_cast<struct sockaddr*>(&serverAddress), sizeof(serverAddress)) == -1) {
    std::cerr << "Error connecting to the server" << std::endl;
    close(clientSocket);
    return 1;
  }

  std::cout << "Connected to the server" << std::endl;

  // Send a message to the server
  const char* message = "Hello, server!";
  ssize_t bytesSent = send(clientSocket, message, strlen(message), 0);
  if (bytesSent == -1) {
    std::cerr << "Error sending data to the server" << std::endl;
    close(clientSocket);
    return 1;
  }

  // Receive the server's response
  char buffer[BUFFER_SIZE];
  ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
  if (bytesRead == -1) {
    std::cerr << "Error receiving data from the server" << std::endl;
    close(clientSocket);
    return 1;
  }

  buffer[bytesRead] = '\0';
  std::cout << "Received response from the server: " << buffer << std::endl;

  // Close the client socket
  close(clientSocket);

  return 0;
}