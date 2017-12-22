#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
  perror(msg);
  exit(1);
}

int main(int argc, char *argv[])
{
  int sockfd, newsockfd, portno;
  socklen_t clilen;
  char buffer[256];
  struct sockaddr_in serv_addr, cli_addr;
  int n;

  if (argc < 2)
  {
    fprintf(stderr,"Error, no port provided\n");
    exit(1);
  }
  // socket(int domain, int type, int protocol)
  sockfd = socket(AF_INET, SOCK)STREAM, 0)

  if (sockfd < 0)
  {
    error("Error opening socket");
  }

  bzero((char *) &serv;_addr, sizeof(serv_addr));

  portno = atoi(argv[1]);

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno)

  if (bind(sockfd,(struct sockaddr *) &serv;_addr,
           sizeof(serv_addr)) < 0)
           error("Error on binding");

  listen(sockfd,5);

  clilen = sizeof(cli_addr);

  newsockfd = accept(sockfd,
                  (struct sockaddr *) &cli;_addr, &clilen;);
  if (newsockfd < 0)
      error("Error on accept");

  printf("server: got connection from %s port %d\n",
                inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

  send(newsockfd, "Hello, World!\n",13,0);

  bzero(buffer,256);

  n = read(newsockfd, buffer, 255);
  if (n < 0) error("Error reading from socket");
  printf("Here is the message: %s\n", buffer);

  close(newsockfd);
  close(sockfd);
  return 0;

}
