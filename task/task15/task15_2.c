/**********************************************************************
 *@file task15_2.c
 *@brief this program just creating dynamic and static memory and display its address for the uderstanding of memory aligned in processor
 *@parameter void
 *@return integer
 *@note just run and check the output
 *
 *@Author Praveen P
 *@Created date 5/07/23
 *@version 1
 *@bug
 *@last modified data 6/07/23
 ***********************************************************************/


#include<stdio.h>
#include<stdlib.h>
/*********************************************************************************************
 *@brief tis function allocate set of block of memory for integer and return back its address
 *@parameter integer
 *@return integer address
 **********************************************************************************************/
int * allocate_memory(int n)
/*********************************************************************************************
 *@brief tis function is used to print the memory address of  list of integer array
 *@parameter integer pointer
 *@return void
 **********************************************************************************************/
void print_address(int *p)
/*********************************************************************************************
 *@brief tis function is used to declare and display the local variable address
 *@parameter void
 *@retun void
 **********************************************************************************************/
void print_local()

 /**************************************************
 44  *from this heap memory is accessedfrom low to high 
 45  *stack memory is accessed from high to low
 46 **************************************************/

int main()
{
	int *num=allocate_memory(5);
	print_address(num);
	print_local();
}
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

