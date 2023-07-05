#include<stdio.h>
unsigned int base=0;
unsigned int expo=0;
long int result=1;
long int exponential(int,int);
int main()
{
printf("Enter the base value ");
scanf("%d",&base);
printf("Enter the power ");
scanf("%d",&expo);
long value=exponential(base,expo);
printf("%ld",value);
}

long int exponential(int base,int power)
{
if(power<1)
{
return result;
}
else
{
result=base*result;
return(exponential(base,(--power)));
}
}
