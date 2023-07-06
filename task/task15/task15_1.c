/**********************************************************************
 *@file task15_1.c
 *@brief this program is just to show case the memory alignment 
 *@parameter void
 *@return void
 *@note after compiling this file you can check the memory alignment and value using the following commands
 *size program output(compiled file)
 *objdump -h => whih gives the memory alignment
 *@Author Praveen P
 *@Created date 5/07/23
 *@version 1
 *@bug
 *@last modified data 6/07/23
 ***********************************************************************/



#include<stdio.h>
unsigned int val[100]={5};// global variable initialized with value 5
unsigned int data[100];// non initialized

/****************************
 *dummy function
 *noing get and nothing return
***************************/
void function()
{

}
int main()
{
	unsigned int num[100];//local variable if you initialized or not it take garbage value as default
}
