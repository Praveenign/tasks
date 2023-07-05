  #include<stdio.h>                         
  #include<stdlib.h>
  #include<string.h>
  #include<unistd.h>
  #include<arpa/inet.h>
 int client_sock=0;
struct sockaddr_in client_addr;
char *ip="127.0.0.1";
char buffer[102];
int n=0;
int main()
{
printf("initialized\n");
client_sock=socket(AF_INET,SOCK_STREAM,0);
if(client_sock<0)
{
printf("ERROR");
}
else
{
printf("Socket connected\n");
 memset(&client_addr,'\0',sizeof(client_addr));
 client_addr.sin_family=AF_INET;
 client_addr.sin_port=5600;
 client_addr.sin_addr.s_addr=inet_addr(ip);
n=connect(client_sock,(struct sockaddr *)&client_addr,sizeof(client_addr));
perror("connecterr");
if(n<0)
{
printf("error in connection=%d\n",n);
}
else
{
printf("client connected to server\n");
}
bzero(buffer,sizeof(buffer));
strcpy(buffer,"welcome to server");
printf("%s\n",buffer);
unsigned int message=0x1234567;
unsigned int  data=ntohl(message);
send(client_sock,&data,sizeof(buffer),0);
//send(client_sock,buffer,sizeof(buffer),0);
bzero(buffer,102);
recv(client_sock,buffer,sizeof(buffer),0);
printf("server :%s\n",buffer);
close(client_sock);
printf("disconnect from server");
}
return 0;
}
