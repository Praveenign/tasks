#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int server_sock=0,client_sock=0;
struct sockaddr_in server_addr,client_addr;
char *ip="127.0.0.1";
int n=0;
char*p; 
char buffer[102];
unsigned int port=5600;
socklen_t addr_size;
int main(int arv,char **arg)
{
printf("ar=%d\n",arv);
ip=arg[1];
printf("ip-%s\n",ip);
port=atoi(arg[2]);
printf("port=%d\n",port);
	printf("Initialized\n");
	server_sock=socket(AF_INET,SOCK_STREAM,0);
	perror("perr");
	printf("socket%d\n",server_sock);
	if(server_sock<0)
		{
		printf("Error in socket%d\n",server_sock);
		}
	else
		{
		printf("socket connected\n");
		memset(&server_addr,'\0',sizeof(server_addr));
		server_addr.sin_family=AF_INET;
		server_addr.sin_port=port;
		server_addr.sin_addr.s_addr=inet_addr(ip);
		n=bind(server_sock,(struct sockaddr*)&server_addr,sizeof(server_addr));
		printf("Bind %d\n",n);
		 perror("perr");

		if(n<0)
			{
			printf("Bind error%d\n",n);
			perror("perr");
			}
		else
			{
			printf("Binded Successfully\n");
			listen(server_sock,1);
			perror("lsitenerr");
			printf("listening");
			}
		}
//	while(1)
		{
		addr_size =sizeof(client_addr);
		client_sock=accept(server_sock,(struct sockaddr*)&client_addr,&addr_size);
		perror("acpterr");
		bzero(buffer,102);
unsigned int data=0;
		recv(client_sock,&data,sizeof(data),0);
		perror("receive");
unsigned int message=htonl(data);
		printf("client=%x\n",message);
		bzero(buffer,102);
		strcpy(buffer,"thanks");
		printf("server %s\n",buffer);
		send(client_sock,buffer,sizeof(buffer),0);
		perror("send");
		close(client_sock);
		close(server_sock);
		perror("close");
		printf("client disconnected");
		}
	return 0;
}
