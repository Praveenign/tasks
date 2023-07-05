#include<stdio.h>
#include<stdlib.h>

int * allocate_memory(int n)
{
int *number=(int *)malloc(sizeof(int));
return number;
}
void print_address(int *p)
{
for(int i=0;i<5;i++)
{
printf("add=%p\n",p);
p++;
}
}
void print_local()
{
int c;
char m;
float j;
printf("add c=%p\n",&c);
printf("add m=%p\n",&m);
printf("add j=%p\n",&j);
}
int main()
{
/**************************************************
 *from this heap memory is accessedfrom low to high 
 *stack memory is accessed from high to low
**************************************************/
int *num=allocate_memory(5);
print_address(num);
print_local();
}
