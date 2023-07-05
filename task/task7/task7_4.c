#include<stdio.h>
#include<stdbool.h>
struct student
{
char name[20];
int mark;
bool (*compare)(struct student,struct student);
};
void print(struct student*,int);
  bool descending(struct student ,struct student);
  bool ascending(struct student ,struct student );  
void sort_student(struct student *,int ,bool(*compar)(struct student,struct student));
void swap(struct student *,struct student *);

 
int main()
{

struct student std[3]={
{"praveen",100,ascending},
{"naveen",98,descending},
{"pradeep",95,ascending}
};

print(std,3);
sort_student(std,3,ascending);
 print(std,3);
sort_student(std,3,descending);

 print(std,3);


printf("Completed");
return 0;
}
bool ascending(struct student s1,struct student s2)
{
return(s1.mark>s2.mark);
}
bool descending(struct student s1,struct student s2)
{
return(s1.mark<s2.mark);
}
void print(struct student s[],int size)
{
for(int i=0;i<size;i++)
{
printf("\nName=%s\n",s[i].name);
printf("mark=%d\n",s[i].mark);
} 
}
void sort_student(struct student s[],int size,bool(*compar)(struct student,struct student))
{
for(int i=0;i<size;i++)
{
for(int j=i+1;j<size;j++)
{
if(compar(s[i],s[j]))
{
swap(&s[i],&s[j]);
}
}
}
}
void swap(struct student *s1,struct student *s2)
{
struct student s3;
s3=*s1;
*s1=*s2;
*s2=s3;
}


