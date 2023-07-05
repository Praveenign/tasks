/**********************************************************************
 *@file task5_4.c
 *@brief this create a struct file for student using bitfield and prints its value and size 
 *@parameter character,integer
 *@return void
 *@ note actual and displayed memory size will be due to structure padding
 *@Author Praveen P
 *@Created date 25/06/23
 *@version 1
 *@bug
 *@last modified data 25/06/23
 ***********************************************************************/
#include<stdio.h>
#include<string.h>
#include<stddef.h>
struct student
{
char name[20];
unsigned int age:6;
unsigned char grade:4 ;
};
int main()
{
//printf("%d\n",sizeof(struct student));
struct student students[3]={
{"praveen",25,1},
{"Pradeep",23,'B'},
{"Naveen",26,'C'}
};

for(int i=0;i<3;i++)
{
printf("%d.)",(i+1));
printf("Name = %s\n",students[i].name);
printf("Age = %u\n",students[i].age);
printf("Grade = %u\n",students[i].grade);
}
printf("Original size will be 22 bytes  but due to structure padding actual size is");
printf("%zu\n",sizeof(struct student));
//printf("%zu\n",offsetof(struct student, age));
//printf("%zu\n",offsetof(struct student, grade));
return 0;
}
