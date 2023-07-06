/**********************************************************************
 *@file task14_2.c
 *@brief this program gives detail explanation regarding safe and unsafe handler while signal handling occurs
 *@parameter void
 *@return integer
 *@note have to give exact signal number or name for their action
 *
 *@Author Praveen P
 *@Created date 5/07/23
 *@version 1
 *@bug
 *@last modified data 5/07/23
 ***********************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
char array[100]="welocme to the ignitorim";
int n=1;
/**********************************************************************************************
*@brief this function prints the global array while SIGINT signal occurs
*@parameter integer
*@return void
*************************************************************************************************/
void unsafe_handler(int sig)
{
	if(sig==SIGINT)
	{
		printf("%s\n",array);
	}
}
/**********************************************************************************************
*@brief this function prints the global array  in the file while SIGTERM signal occurs
*@parameter integer
*@return void
*************************************************************************************************/
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
/**********************************************************************************************
*@brief in main we have change the string(global array value) continuosly in infinite loop 
*@parameter integer
*@return void
*************************************************************************************************/

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
	return 0;
}

