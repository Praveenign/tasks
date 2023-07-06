/**********************************************************************
 *@file task16_1.c
 *@brief this program just like a calculator perform some arithametic operation
 *@parameter integer
 *@return integer
 *@note this program is executed using static library concept so need to create a static library before execute
 *gcc -c filename with extension -o the filename with extension as object
 *arr rcs lib<libraryname with.a extension> object file
 *gcc program name -L.(dot important) -l<lib name without extension> -o output
 *
 *@Author Praveen P
 *@Created date 6/07/23
 *@version 1
 *@bug
 *@last modified data 6/07/23
 ***********************************************************************/

#include<stdio.h>
#include"maths.h"
int number1=0;
int number=0;
int main()
{
	printf("Enter the first value ");
	scanf("%d",&number);
	printf("Enter the second value");
	scanf("%d",&number1);
	printf("sum=%d\n",sum(number,number1));
	printf("subtract=%d\n",sub(number,number1));
	return 0;
}


