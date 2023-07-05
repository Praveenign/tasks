/**********************************************************************
 *@file tas4_1.c
 *@brief this program get two number as integer and print the average value as float by using explict type casting 
 *@parameter integer
 *@return void
 *@note print only two digit in fraction
 *
 *@Author Praveen P
 *@Created date 22/06/23
 *@version 1
 *@bug
 *@last modified data 22/06/23
 ***********************************************************************/
 #include<stdio.h>
int number1;
int number2;

int main()
{
	printf("Enter the values to find average\n");
	printf("Enter the number1   ");
	scanf("%d",&number1);
	printf("Enter the number2   ");
	scanf("%d",&number2);
	float average=(float)(number1+number2)/2;
	printf("%.2f\n",average);


}
