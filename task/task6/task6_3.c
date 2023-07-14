/**********************************************************************
 *@file task6_3.c
 *@brief this program executes the tail recursion  
 *@parameter integer
 *@return integer
 *
 *@Author Praveen P
 *@Created date 25/06/23
 *@version 1
 *@bug
 *@last modified data 25/06/23
 ***********************************************************************/
#include<stdio.h>
int number;
long long unsigned int fact(int);
long long unsigned int fact_help(int,long long unsigned int);
long long unsigned int factorial(int );
int main()
{
printf("Enter the factorial number");
scanf("%d",&number);
printf("Tail Recursion = %lld",fact(number));
printf("\nRecursion = %lld",factorial(number));

}
long long unsigned int fact(int n)
{
return(fact_help(n,1));
}
long long unsigned int fact_help(int n,long long unsigned int result)
{
if(n==0)
{
return result;
}
else
{
return(fact_help(n-1,(n*result)));
}
}

long long unsigned int factorial(int num)
{
if(num==0)
{
return 1;
}
else
{
return((num*factorial(--num)));
}
}

