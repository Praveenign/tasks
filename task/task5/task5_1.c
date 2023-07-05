/**********************************************************************
 *@file task5_1.c
 *@brief this program get signed integer as input and doing set and clear position of bits using user interface
 *@parameter unsigned integer
 *@return void
 *
 *@Author Praveen P
 *@Created date 25/06/23
 *@version 1
 *@bug
 *@last modified data 25/06/23
 ***********************************************************************/


#include<stdio.h>
signed int number;
unsigned int binary[32];
int set1_position=0,set2_position=0,clear1_position=0,clear2_position=0;
/********************************************************************************************
 *@ brief convert integer to binary
 *@ parameter integer
 *@ return void
 *
 **************************************************************************************/
void int_binary(int);
/**********************************************************************************
 *@ brief set the bit position 
 *@ parameter integer
 *@ return integer
 *@ note give value and position as parameter
 *******************************************************************************************/

int set_bit(int,int );
/**********************************************************************************
   *@ brief clear the bit position 
   *@ parameter integer
   *@ return integer
   *@ note give value and position as parameter
   *******************************************************************************************/

int clear_bit(int,int);
int main()
{
printf("Enter the number\n");
scanf("%d",&number);
int_binary(number);
printf("\n Enter two position between 0 to 31 to set bits\n");
printf("Enter first position");
scanf("%d",&set1_position);
printf("enter second position");
scanf("%d",&set2_position);
printf("Enter two position between 0 to 31 to clear bits\n");
printf("Enter first position");
scanf("%d",&clear1_position);
printf("Enter second postion ");
scanf("%d",&clear2_position);
number=set_bit(number,set1_position);
number=set_bit(number,set2_position);
printf("After set bit number=   %d \n",number);
int_binary(number);
number=clear_bit(number,clear1_position); 
number=clear_bit(number,clear2_position);
printf("\nAfter clear bit number=   %d \n",number);
int_binary(number);    
}

void int_binary(int number)
{
int data =number;
for(int i=0;i<32;i++)
  {
  if(number&1)
  {
  binary[i]=1;
  }
  else
  {
  binary[i]=0;
  }
  number=number>>1;
  }
  printf("Binary value for %d is ",data);
  for(int i=31;i>=0;i--)
  {
  printf("%d",binary[i]);                                                                                                                                                                                 }

}
int set_bit(int value,int position)
{
value|=(1<<position);
return value;
}
int clear_bit(int value,int position)
{
value&=~(1<<position);
return value;
}

