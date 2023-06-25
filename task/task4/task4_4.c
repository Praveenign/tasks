/*
 *@Author : Praveen P 
 *@ Tool  : vim cscope
 *@Platform : Linux
 *@Date  :23/06/23
 *@version1
 *@last modified 23/06/23
 *@bugs - 
 *
 *
 *@breif This program creates a certain block of dynamic memory  and its assign to char and later it type casting to integer pointer and uses its tp store integer values and free that memory at last using free function/////
* library used -standard library studio and stdlib
*@parameter int pointer  and char pointer
*return type void
*/



#include<stdio.h>
#include<stdlib.h>


int main()
{
char* ptr=(char*)malloc(16*sizeof(char));

int *pt1=(int*)ptr;
*pt1=10;
pt1++;
*pt1=20;
pt1++;
*pt1=30;
pt1++;
*pt1=40;

for(int i=0;i<4;i++)
{
printf("Address=%p,value=%d\n",pt1,*pt1);
pt1--;
}
printf("base address of char pointer=%p",ptr);

free(ptr);

}
