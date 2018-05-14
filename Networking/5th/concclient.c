#include<stdio.h>
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#define MAX_MSG 100
#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 1550
#define CLIENT_ADDR "127.0.0.1"
#define CLIENT_PORT 2500
main()
{
	int n,sd,newsd,clilen,j;
	struct sockaddr_in cliaddr,servaddr;
	char line[MAX_MSG];
	bzero((char*)&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr(SERVER_ADDR);
	servaddr.sin_port=htons(SERVER_PORT);
	sd=socket(AF_INET,SOCK_STREAM,0);
	printf("\nsocket is created");
	connect(sd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	printf("\nconnected to server successfully.");
	clilen=sizeof(cliaddr);
	int len=sizeof(servaddr);
	do{
		printf("\nenter string to send to server : ");
		scanf("%s",line);
		send(sd,line,strlen(line)+1,0);
		printf("data sent (%s)\n",line);
		memset(line,0*0,MAX_MSG);
		n=recv(sd,line,MAX_MSG,0);
		printf("no of bytes received : %d",n);
		line[n]='\n';
		printf("\nResult = %s\n",line);
	}while(strcmp(line,"quit"));
	printf("\nclosing connection with the server");
	close(sd);
}
