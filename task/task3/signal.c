/**********************************************************************
 *@file signal.c
 *@brief this program gives detail on whcih signal has been occured and what was its action taken 
 *@parameter integer
 *@return void
 *@note have to give exact signal number or name for their action
 *
 *@Author Praveen P
 *@Created date 22/06/23
 *@version 1
 *@bug
 *@last modified data 22/06/23
 ***********************************************************************/





#include<stdio.h>
#include<signal.h>
/********************************************************************************
 *@brief it just divide by zero to create a floating point error signal
 *@parameter integer
 *@return void 
 *****************************************************************************/
void divide();
/********************************************************************************
 *@brief this funvtion is assaigned one pointer to null and derefering it to produce segmentation fault signal
 *@parameter void
 *@return void
 ************************************************************************************/

void pointer();

/*********************************************************************************************
 *@brief tis function is called when the error singnal is initiated
 *@parameter integer
 *@void
 **********************************************************************************************/

void sig_handler(int);
/****************************************************************************************
 *@brief this function is helps to run the program to infinite loop which helps to create interupt signal by using ctrl+c
 *@parameter void
 *@return void
******************************************************************************************/

void loop();

/****************************************************************************************************
 *@ functions used
 * SIGSEGV -SEGMENTATION ERROR by calling function pointer or by giving signal from terminal kill -SIGSEV PID
 * SIGFPE - FLOATING POINT ERROR by calling divide function or by giving signal from terminal kill -SIGFPE PID
 * SIGINT - INTERUPT SIGNAL by pressing ctrl + C or by giving signal from the terminal kill -SIGINT PID
 * SIGTERM - TERMINATED SIGNAL -which was initiated by external terminal kill -SIGTERM PID
 * AVAILABLE SIGNALS
 * 1) SIGHUP	 2) SIGINT	 3) SIGQUIT	 4) SIGILL	 5) SIGTRAP
 * 6) SIGABRT	 7) SIGBUS	 8) SIGFPE	 9) SIGKILL	10) SIGUSR1
 * 11) SIGSEGV	12) SIGUSR2	13) SIGPIPE	14) SIGALRM	15) SIGTERM
 * 16) SIGSTKFLT	17) SIGCHLD	18) SIGCONT	19) SIGSTOP	20) SIGTSTP
 * 21) SIGTTIN	22) SIGTTOU	23) SIGURG	24) SIGXCPU	25) SIGXFSZ
 * 26) SIGVTALRM	27) SIGPROF	28) SIGWINCH	29) SIGIO	30) SIGPWR
 * 31) SIGSYS	34) SIGRTMIN	35) SIGRTMIN+1	36) SIGRTMIN+2	37) SIGRTMIN+3
 * 38) SIGRTMIN+4	39) SIGRTMIN+5	40) SIGRTMIN+6	41) SIGRTMIN+7	42) SIGRTMIN+8
 * 43) SIGRTMIN+9	44) SIGRTMIN+10	45) SIGRTMIN+11	46) SIGRTMIN+12	47) SIGRTMIN+13
 * 48) SIGRTMIN+14	49) SIGRTMIN+15	50) SIGRTMAX-14	51) SIGRTMAX-13	52) SIGRTMAX-12
 * 53) SIGRTMAX-11	54) SIGRTMAX-10	55) SIGRTMAX-9	56) SIGRTMAX-8	57) SIGRTMAX-7
 * 58) SIGRTMAX-6	59) SIGRTMAX-5	60) SIGRTMAX-4	61) SIGRTMAX-3	62) SIGRTMAX-2
 * 63) SIGRTMAX-1	64) SIGRTMAX
 *
 *********************************************************************************************************/


int main(void)

{          
       // signal (int sig,function call)- this function maynot work in all operating system
	signal(SIGSEGV,sig_handler);
	signal(SIGFPE,sig_handler);
    	if (signal(SIGINT, sig_handler) == SIG_ERR)
  		printf("\ncan't catch SIGINT\n");
    	if (signal(SIGUSR1, sig_handler) == SIG_ERR)
        	printf("\ncan't catch SIGUSR1\n");
    	if (signal(SIGKILL, sig_handler) == SIG_ERR)
        	printf("\ncan't catch SIGKILL\n");
    	if (signal(SIGSTOP, sig_handler) == SIG_ERR)
        	printf("\ncan't catch SIGSTOP\n");

   	//divide();
   	//pointer();
	loop();
    	//printf("hi");
	return 0;
}
void sig_handler(int signo)
{
   	if (signo == SIGINT)
    		printf("received SIGINT\n");
   	else if (signo == SIGSEGV)
        	printf("received SIGSEGV\n");
    	else if (signo == SIGFPE)
        	printf("received SIGFPE\n");
    	else if (signo == SIGTERM)
        	printf("received SIGTERM\n");
	else if (signo == SIGSTOP)
        	printf("received SIGSTOP\n");

}

void divide()
{
	int num;
 	num=10/0;
   	printf("%d",num);
}
void pointer()
{
	int *ptr=NULL;
	printf("%d",*ptr);
}
void loop()
{
	while(1);
}
