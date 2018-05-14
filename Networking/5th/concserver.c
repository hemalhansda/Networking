#include<stdio.h>
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#define MAX_MSG 100
#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 1550
main()
{
	int n,sd,newsd,clilen;
	struct sockaddr_in cliaddr,servaddr;
	char line[MAX_MSG];
	clilen=sizeof(cliaddr);
	bzero((char*)&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr(SERVER_ADDR);
	servaddr.sin_port=htons(SERVER_PORT);
	sd=socket(AF_INET,SOCK_STREAM,0);
	if(sd>=0)
	{
		printf("\nsocket is created successfully.");
	}
	int k=bind(sd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	if(k>=0)
	{
		printf("\nbind successfully.");
	}
	else
	{
		printf("\nbind unsuccessful.");
	}
	listen(sd,10);
	while(1)
	{
		newsd=accept(sd,(struct sockaddr *)&cliaddr,&clilen);
		int id=fork();
		if(id==0)
		{
			close(sd);
			do
			{
				memset(line,0,MAX_MSG);
				n=recv(newsd,line,MAX_MSG,0);
				printf("no of bytes received : %d",n);
				printf("Data received :%s",line);
				printf("\nenter string to send to client : ");
				memset(line,0,MAX_MSG);
				scanf("%s",line);
				send(newsd,line,strlen(line)+1,0);
				printf("data sent (%s)\n",line);
			}while(strcmp(line,"quit"));
		}
		close(newsd);
	}
}
