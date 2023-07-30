#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define FILE_TO_SEND "file.txt"

int main(){

  char *ip = "127.0.0.1";
  int port = 5566;

  int sock;
  struct sockaddr_in addr;
  socklen_t addr_size;
  char buffer[1024];
  int n;

  FILE *file;

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0){
    perror("Socket error");
    exit(1);
  }
  printf("TCP server socket created.\n");

  memset(&addr, '\0', sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = port;
  addr.sin_addr.s_addr = inet_addr(ip);

  connect(sock, (struct sockaddr*)&addr, sizeof(addr));
  printf("Connected to the server.\n");

  while (1) {
    printf("Enter 'send' to send the file contents to the server: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\r\n")] = 0; 

    if (strcmp(buffer, "send") == 0) {
      file = fopen(FILE_TO_SEND, "r");
      if (file == NULL) {
        perror("File open error");
        continue;
      }

      bzero(buffer, 1024);
      ssize_t bytes_read = fread(buffer, 1, sizeof(buffer) - 1, file);
      if (bytes_read <= 0) {
        perror("File read error");
        fclose(file);
        continue;
      }

      printf("Client: Sending file contents...\n");
      send(sock, buffer, bytes_read, 0);
      printf("Client: File contents sent to the server.\n");

      fclose(file);
    }
  }

  close(sock);
  printf("Disconnected from the server.\n");

  return 0;
}
