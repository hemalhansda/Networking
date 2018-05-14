#include <stdio.h>

#include <sys/socket.h>

#include <arpa/inet.h>

#include <stdlib.h>

#include <string.h>

#include <unistd.h>

#define RCVBUFSIZE 32

#define MAXPENDING 5

char echoBuffer[RCVBUFSIZE];

int recvMsgSize;

int main(int argc, char *argv[]){

 char line[500];

 char echoString[200];

 int servSock;

 int clntSock;int n;

 struct sockaddr_in echoServAddr;

 struct sockaddr_in echoClntAddr;

 unsigned short echoServPort;

 unsigned int clntLen;

 int bPerm=1;

 if (argc != 3){

 printf("Usage: %s <Broadcast IP> <Server Port>\n", argv[0]) ;

 exit(1);

 }

 echoServPort = atoi(argv[2]);

 servSock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);

 printf("Broadcast socket created: %d\n",servSock);

 memset(&echoServAddr, 0, sizeof(echoServAddr));

 setsockopt(servSock, SOL_SOCKET, SO_BROADCAST, (void *) &bPerm,sizeof(bPerm));

 echoServAddr.sin_family = AF_INET;

 echoServAddr.sin_addr.s_addr = inet_addr(argv[1]);

 echoServAddr.sin_port = htons(echoServPort);

 do{

 memset(line,0x0,500);

 printf("Enter string to send to client: " );

 scanf("%s", echoString);

 sendto(servSock, echoString, strlen(echoString)+1, 0, (struct sockaddr *)&echoServAddr,

sizeof(echoServAddr));

 printf("Data sent : %s\n", echoString);

 }while (abs(strcmp(echoString,"quit")));

 printf("Closing connection with host [IP %s, UDP port%d]\n",inet_ntoa(echoClntAddr.sin_addr),ntohs(echoClntAddr.sin_port));

}
