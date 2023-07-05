#include<stdio.h>
#include<stdbool.h>
int array[]={2,4,5,7,8,3};
bool ascending(int ,int);
bool descending(int,int);
void swap(int *,int *);
void sort_array(int*,int ,bool(*compare)(int,int));
void print(int *,int);

int main()
{
//printf("1\n");
int size=sizeof(array)/sizeof(array[0]);
sort_array(array,size,ascending);
//printf("2\n");
print(array,size);
printf("\n");
sort_array(array,size,descending);
print(array,size);

}

bool ascending(int a ,int b)
{
//printf("5\n");
return(a<b);
}
bool descending(int a,int b)
{
return(a>b);
}
void swap(int *a,int *b)
{
int temp=*a;
*a=*b;
*b=temp;
}
void print(int array[],int size)
{
for(int i=0;i<size;i++)
{
printf("%d",array[i]);
}
}
void sort_array(int array[],int size,bool(*compare)(int,int))
{
// printf("3\n");
//printf("\n%d",compare(22,33));
for(int i=0;i<size;i++)
{
for(int j=i+1;j<size;j++)
{
if(compare(array[i],array[j]))
{
swap(&array[i],&array[j]);
//printf("4\n");
}
}
}


}
