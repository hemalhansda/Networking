#include <stdio.h>

#include <sys/socket.h>

#include <arpa/inet.h>

#include <stdlib.h>

#include <string.h>

#include <unistd.h>

#define RCVBUFSIZE 32

int main(int argc, char *argv[]){

 int sock;

 struct sockaddr_in echoServAddr;

 unsigned short echoServPort;

 char *servlP;

 char *echoString;

 char line[500];

 char echoBuffer[RCVBUFSIZE];

 unsigned int echoStringLen;

 int len;

 int p;

 printf("%d",argc);

 if (argc!=2)

 {

 printf("Usage: %s <Broadcast Port>\n", argv[0]);

 exit(1);

 }

 echoServPort = atoi(argv[1]);

 sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);

 printf("Broadcast recieving socket created %d\n",sock);

 memset(&echoServAddr, 0, sizeof(echoServAddr));

 echoServAddr.sin_family = AF_INET;

 echoServAddr.sin_addr.s_addr = htonl(INADDR_ANY);

 echoServAddr.sin_port = htons(echoServPort);

 bind(sock, (struct sockaddr *) &echoServAddr, sizeof(echoServAddr));

 len=sizeof(echoServAddr);

 do{

 memset(line,0x0,500);

 int n=recvfrom(sock,line,500,0,(struct sockaddr *) &echoServAddr,&len);

 line[n]='\n';

 printf("Recieved from host [IP %s, TCP port %d]: %s\n",inet_ntoa(echoServAddr.sin_addr),ntohs(echoServAddr.sin_port), line);

 }while(strcmp(line,"quit"));

 printf("Closing server-client connection\n");

 close(sock);

 exit(0);

}

