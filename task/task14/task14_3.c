#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
char array[100]="welocme to the ignitorim";
int n=1;
void unsafe_handler(int sig)
{
if(sig==SIGINT)
{
printf("%s\n",array);
}
}
void safe_handler(int sig)
{
if(sig==SIGTERM)
{
FILE *file;
file=fopen("praveen.txt","a");
perror("Result");
if(file!=NULL)
{
int numof_bytes=fwrite(array,1,strlen(array),file);
perror("write");
fclose(file);
}

}
}

int main()
{
signal(SIGINT,unsafe_handler);
signal(SIGTERM,safe_handler);
while(1)
{
//printf("n=%d\n",n);
if(n==1)
{
strcpy(array,"value may be changed at any time ");
n=0;
}
else
{
strcpy(array,"data can cause the result to crash");
n=1;
}
}
}

