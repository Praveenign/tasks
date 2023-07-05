#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int * create_array(int n)
{
int *number=(int*)malloc(n*sizeof(int));
return number;
}
void fill_array(int *number,int n)
{
srand(0);
for(int i=0;i<n;i++)
{
*number=rand();
number++;
}
}
void print_array(int *number,int n)
{
for(int i=0;i<n;i++)
{
printf("array=%d\n",*number);
number++;
}

}
int main()
{
int *p=create_array(5);
fill_array(p,5);
print_array(p,5);
free(p);
print_array(p,5);
}
