/**********************************************************************
 *@file task4_3.c
 *@brief this program get the float value from user and prints its equivalent binary value and also access its bits as integer using type punning
 *@parameter float
 *@return integer
 *@note carefull while using union because bytes may vary for data types for different platform
 *
 *@Author Praveen P
 *@Created date 22/06/23
 *@version 1
 *@bug
 *@last modified data 22/06/23
 ***********************************************************************/

#include<stdio.h>
/*********************************
*union is created to access float as unsigned integer
*
***************************************/
union punning
{
unsigned int data;
float data1;
};
float number=0;  // input float variable
//unsigned int binary[32];   
unsigned int expo[8];  // to store exponential value for bit in float
unsigned int numerator[8]; //to store  binary value  for decimal 
unsigned int display_const; 
unsigned int fact[24];
unsigned int exponent[8];
unsigned int display[32];
int fact_const=0;
int expo_const=0;
int num_const=0;
int main()
{
	union punning object;
	printf("Enter the floating number");
	scanf("%f",&number);
	float disp=number;
	if(number>0)
	{
		display[display_const]=0;
		display_const++;   
	}
	else
	{
		display[display_const]=1;
		display_const++;
		number*=-1;
	}

	int quotient =(int)number;
	float fraction =number-quotient;
	while(quotient>0)
	{
		numerator[num_const]=quotient%2;
		quotient=quotient/2;
		num_const++;
	}
	while((fraction<1&&fraction>0)&&fact_const<23)
	{
	    	fraction=fraction*2;
	    	if(fraction>=1)
	    	{
		    fraction=fraction-1;
		    fact[fact_const]=1;
		    fact_const++;
		}
		else
		{
			fact[fact_const]=0;
			fact_const++;
		}
	}	
	unsigned int expo=num_const-1+127;

  	while(expo>0)
        {
                exponent[expo_const]=expo%2;
                expo=expo/2;
                expo_const++;
        }

	while(expo_const>0)
	{
		display[display_const]=exponent[expo_const-1];
		expo_const--;
		display_const++;
	}  

	display_const=9;
	while(num_const>1)
	{
		display[display_const]=numerator[num_const-2];
		num_const--;
		display_const++;
	}
	int i=0;
	//printf("fact=%d\n",fact_const);
	while(i<=fact_const-1)
	{
		display[display_const]=fact[i];
		//printf("disp=%d",display[display_const]);
		display_const++;
		i++;
	}
	printf("Binary for the floating point %f is",disp);
	for(int j=0;j<32;j++)
	{
		printf("%d",display[j]);
	}

	object.data1=disp;
	printf("\nunion float=%f\n",object.data1);
	printf("union unsigned int =%d\n",object.data);
	unsigned int result1=object.data;
	unsigned int result2=(unsigned int)object.data1;
	printf("result1=%d\n",result1);
	printf("result2=%d\n",result2);
}







