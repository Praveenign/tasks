/**********************************************************************
 *@file task5_2.c
 *@brief this program gets number number and swap using xor operation
 *@parameter integer
 *@return void
 *
 *@Author Praveen P
 *@Created date 25/06/23
 *@version 1
 *@bug
 *@last modified data 25/06/23
 ***********************************************************************/


#include<stdio.h>
int number1;
int number2;
int main()
{
	printf("enter the first number");
	scanf("%d",&number1);
	printf("enter the second number");	
	scanf("%d",&number2);
	number1=number1^number2;
	number2=number1^number2;
	number1=number1^number2;
	printf("After swap number1=%d\n",number1);
	printf("After swap number2=%d",number2);
}
