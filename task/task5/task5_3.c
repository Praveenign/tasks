/**********************************************************************
 *@file task5_3.c
 *@brief this program get a character and make bitwise operation  with mask id from the user with the help of AND and OR operator 
 *@parameter character and integer
 *@return integer
 *
 *@Author Praveen P
 *@Created date 25/06/23
 *@version 1
 *@bug
 *@last modified data 25/06/23
 ***********************************************************************/
#include<stdio.h>
#include<stdint.h>
int bin[8];
char name;
uint8_t mask;
/**********************************************************************************
 *@ brief convert unsigned integer of 8 bits to its binary number
 *@ parameter unsigned 8 bit integer
 *@ return void
 ******************************************************************************/
void binary(uint8_t);
int main()
{
	printf("Enter the character  ");
	scanf("%c",&name);
	printf("Ascii value = %d\n",name);
	binary(name);
	printf("\nEnter the mask id between 0 to 255 for AND operation  ");
	scanf("%d",&mask);
	uint8_t mask_result=name&mask;
	printf("After masking with AND operation = %d\n",mask_result);
	binary(mask_result);
	printf("\nEnter the mask id between 0 to 255  for OR operation  ");
	scanf("%d",&mask); 
	mask_result=name|mask;
	printf("After masking with  OR operation = %d\n",mask_result);
	binary(mask_result);  
}
void binary(uint8_t name)
{
	for(int i=0;i<8;i++)
	{
		if(name&1)
		{
			bin[i]=1;
		}
		else
		{
			bin[i]=0;
		}
		name=name>>1;
	}
	for(int i=7;i>=0;i--)
	{
		printf("%d",bin[i]);
	}
}
