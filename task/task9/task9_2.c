#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
char *name;
int age;
char **course;
};
struct student * create_student(char *name,int age,char **course,int numofcourse)
{
struct student * newstudent=(struct student *)malloc(sizeof(struct student));
if(newstudent==NULL)
{
printf("Error in memory allocation\n");
return NULL;
}
printf("add=%p\n",newstudent);
newstudent->name=(char *)malloc(sizeof(name));
if(newstudent->name==NULL)
{
printf("Error in memory allocation\n");
  free(newstudent);
  return NULL;
}
strcpy(newstudent->name,name);
newstudent->age=age;
newstudent->course=(char**)malloc(sizeof(char*)*numofcourse);
if(newstudent->course==NULL)
{
printf("Error in memory allocation\n");
	free(newstudent->name); 
   free(newstudent);
    return NULL;
}
for(int i=0;i<numofcourse;i++)
{
newstudent->course[i]=(char *)malloc(sizeof(course[i]));
strcpy(newstudent->course[i],course[i]);
}

return newstudent;
}
void print(struct student *new,int numofcourse)
{
printf("%s\n",new->name);
printf("age=%d\n",new->age);
for(int i=0;i<numofcourse;i++)
{
printf("course=%s\n",new->course[i]);
}
}
void delete(struct student * new)
{
if(new!=NULL)
{
free(new->name);
free(new->course);
free(new);
}
}


int main()
{
char *course[]={"maths","physics","science","social","chemistry","computr science"};
struct student * new=create_student("praveen",25,course,3);
struct student * new1=create_student("naveen",26,&course[1],2);
print(new,3);
print(new1,2);
delete(new);
}
