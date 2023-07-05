#include<stdio.h>
#include<stdlib.h>
int value;
char name;
int val=10;
int *ptrval;
int * allocate_memory(int n)
 {
  int * mem=(int*)malloc(sizeof(int)*n);
  return mem;
}
void print_address(int *p)
{
printf("address=%p\n",p);
}

int main()
{
int data;
/***************************************************************************
 *here value is a global variable
 *val is a local variable
 *name is a global character
 *according to theory global variables are stored in data memory
 *after the data memort there is a heap memory so dynamicallyallocated memory will be in above the data memory called heap
 *here val is a local variable so for that memory will be allocated in stack at the time of running that function after completed the function memory alloted for val is getting removed from stack
* Basically stack memory occupies from top so here you may see the difference in the memory address
* ********************************************************************************/
int *ptrval2;
printf("pointer add=%p\n",ptrval);// global pointer denotes null
printf("pointer add=%p\n",ptrval2);
printf("allocate memory=%p\n",allocate_memory(5));
printf("global mem int =%p\n",&value);
printf("global mem int =%p\n",&val); 
printf("global mem char=%p\n",&name);
printf("local mem int =%p\n",&data);
printf("allocate memory=%p\n",allocate_memory(5));
int *ptr=allocate_memory(10);
print_address(ptr);

}

