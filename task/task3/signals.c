#include<stdio.h>
#include<signal.h>



void handler(int sig)
{
	printf("executed");
}


int main()
{
struct sigaction sa;
sa.sa_handler=&handler;
sa.sa_flags=SA_RESTART;

sigaction(SIGTSTP,&sa,NULL);
int num;
//num=10/0;
while(1);

}
