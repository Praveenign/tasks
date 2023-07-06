/**********************************************************************
 *@file task14_2.c
 *@brief this program gives detail on whcih signal has been occured and what was its action taken and how to modify that handler 
 *@parameter integer
 *@return void
 *@note have to give exact signal number or name for their action
 *
 *@Author Praveen P
 *@Created date 5/07/23
 *@version 1
 *@bug
 *@last modified data 5/07/23
 ***********************************************************************/


#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<string.h>
/****************************************************************************************************
*@ brief user defined signal handler function  
*@parameter integer
*@return void
***********************************************************************************************************/
void signal_handler(int sig)
{
	if(sig==SIGINT)
	{
		printf("signal intreupt occured\n");
	}
}
/****************************************************************************************************
*@ brief dummy function to run the program to an infinite loop
*@parameter void
*@return void
***********************************************************************************************************/
void print()
{
	while(1)
	{
		//printf("hu\n");
	}
}
/****************************************************************************************************
*@ brief this can block and unblock the signal using sigpromask
*@parameter void
*@return integer
*note according to the input singnal you may create mask for that ,here is a sample mask function for SIGINT
***********************************************************************************************************/
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
