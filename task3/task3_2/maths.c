/**********************************************************************
 *@maths.c
 *@brief this program performs some mathematical calculation 
 *@parameter integer
 *@return integer
 *@note it is a library function it dosen,t have main function to execute
 *
 *@Author Praveen P
 *@Created date 20/06/23
 *@version 1
 *@bug
 *@last modified data 20/06/23
 ***********************************************************************/


#include<stdio.h>
#include"maths.h"

/*****************************************************************************************
 *@brief this function takes two integer parameter as argument and perform divide operation and give back the result or feedback as integer
 *@parameter integer
 *@return integer
 *@note parameter value as taken only as unsigned integer, and it returns signed value ; negative values are used for error propogation 
 ******************************************************************************************/

int divide(int data,int divident)
{
  if(divident==0)
  {
  return -1;````
  }
  else
  {
  return(data/divident);
  }
}

void test()
{
   printf("\nworked..!!\n");
}
/************************************************************************************************************************************************
 * @brief this function takes first parameter as base and second parameter as power and perform the mathematical operation
 *@paramter integer
 *@return integer
 *@note only unsigned integer is taken as paramter and the calculations are done for 16 bit controller if the operating system is 32bit or more you have to change the comments manually 
 *
*******************************************************************************************************************************/
int exponential(unsigned int value,unsigned int power)
{
	unsigned long long expo=1;
	if(value>256||power>16)// for 32 bit processor value >65536 &  power >32  forunsigned integer
	    {
	    return -1;
	    }
	else
	    {
	    while(power>0)
	    	{
  	    	expo=expo*value;
	    	power--;
	    	}	

	    if(expo>65556)  //for 32 bit processor value >4294967296 power >32  forunsigned integer
		{
		return -2;
		}
	    else
		{
		return((int) expo);
		}	
	    }
}

