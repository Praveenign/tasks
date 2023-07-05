#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<string.h>

void signal_handler(int sig)
{
if(sig==SIGINT)
{
printf("signal intreupt occured\n");
}

}

void print()
{
while(1)
{
//printf("hu\n");
}
}
int main()
{
int num;
signal(SIGINT,signal_handler);
sigset_t signalset;
sigemptyset(&signalset);
sigaddset(&signalset,SIGINT);
sigprocmask(SIG_BLOCK,&signalset,NULL);
printf("Enter to unblock");
scanf("%d",&num);
sigprocmask(SIG_UNBLOCK,&signalset,NULL);
print();
}
