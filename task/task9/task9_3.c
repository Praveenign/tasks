#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int * create_array(int n)
{
int *array=(int*)malloc(sizeof(int)*n);
return array;
}
void fill_array(int *ptr,int size)
{
srand(time(0));
for(int i=0;i<size;i++)
{
*ptr=rand();
ptr++;
}
}
void print_array(int *ptr,int size)
{
for(int i=0;i<size;i++)
{
printf("%d\n",*ptr);
ptr++;
}
}
int main()
{
int * arr=create_array(10);
fill_array(arr,10);
print_array(arr,18);
}
