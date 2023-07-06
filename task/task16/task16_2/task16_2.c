/**********************************************************************
 *@signal.c
 *@brief this program just like a calculator gives the divide and exponential result with error indication
 *@parameter integer
 *@return integer
 *@note using external library function so make ensure that library has been attached or not 
 *
 *Additional information
 *@ this program is executed with the help of shared library (library linked only during at the run timr)
 *gcc -c -fPIC -<filename with extension> -o file.o
 *gcc -shared -o lib<library name with .so> file.o
 *export LD_LIBRARY_PATH=</exact path where library files located>:=LD_LIBRARY_PATH
 *gcc -L<library path> -l<library name> -o output
 *
 *@Author Praveen P
 *@Created date 21/06/23
 *@version 1
 *@bug
 *@last modified data 6/07/23
 ***********************************************************************/

#include<stdio.h>
#include"maths.h"
int value=0; //variable to store divided value
int expo=0;  // varoable to store exponential valuie
int divisor=0;
int number=0;
int base =0;
int exponent=0;
int main()
{
	printf("Enter the divident value ");
	scanf("%d",&number);
	printf("Enter the divisor ");
	scanf("%d",&divisor);
	
        // this function is created for only unsigned value ,negative value is used for error calculation
	value=divide(number,divisor);
	if(value==-1)  // -1 indicates if divisor is zero
		{
		printf("Divisor is zero\n");
		}
	else
		{
		printf("Quotient=%d\n",value);
		}
	printf("Enter the base value ");
	scanf("%d",&base);
	printf("Enter the exponential value ");
	scanf("%d",&exponent);
	
	expo=exponential(base,exponent);
	if(expo==-1||expo==-2)// -1 indicates that buffer overflow due to exponent is above 16,-2 indicates exponential value is beyond the integer limit 

		{
		printf("buffer overflow\n ");
		}
	else
		{
		printf("expo=%d",expo);
		}

	//	printf("executed");


//	test();
	return 0;
}


