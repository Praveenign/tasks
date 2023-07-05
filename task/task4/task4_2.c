/**********************************************************************
 *@file task4_2.c
 *@brief this program get character as input and prints its ascii value using implict and explict type casting and also print its upper case 
 *@parameter character
 *@return void
 *
 *@Author Praveen P
 *@Created date 22/06/23
 *@version 1
 *@bug
 *@last modified data 22/06/23
 ***********************************************************************/
#include<stdio.h>
char name;
int main()
{
	printf("Enter the character   ");
	scanf("%c",&name);
	printf("Ascii value for %c is %d\n",name,name);//implict
	int c=(int)name;
	printf("%d\n",c);//same ascii value
	int upper=c-32;//for lower to upper reduce 32 for upper to lower add 32
	printf("%c\n",(char)upper);//
	char up=(char)c-'a'+'A';
	printf("%c\n",up);

}

