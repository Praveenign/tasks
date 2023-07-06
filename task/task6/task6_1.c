/***************************************************************************************************************************************
 *@file task6_1.c
 *@breif This program gives the exponential value using recursive function/////
 *@parameter integer
 *@return type integer
 
 *@Author : Praveen P 
 *@ Tool  : vim cscope
 *@Platform : Linux
 *@Date  :23/06/23
 *@version1
 *@last modified 23/06/23
 *@bugs - 
 *
 *
****************************************************************************************************************************************/

#include<stdio.h>
unsigned int base=0;
unsigned int expo=0;
long int result=1;

/*************************************************************************************************************************************



*****************************************************************************************************************************************/

long int exponential(int,int);
int main()
{
printf("Enter the base value ");
scanf("%d",&base);
printf("Enter the power ");
scanf("%d",&expo);
long value=exponential(base,expo);
printf("%ld",value);
}

long int exponential(int base,int power)
{
if(power<1)
{
return result;
}
else
{
result=base*result;
return(exponential(base,(--power)));
}
}
