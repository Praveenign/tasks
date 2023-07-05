#include<stdio.h>
int a=10;
int b=2;
int add(int,int);
int sub(int,int);
int multiply(int,int);
int divide(int,int);

int main()
{
printf("Enter the number1  ");
scanf("%d",&a);
printf("Enter the number2  ");
scanf("%d",&b);
int (*fun)(int,int);
int (*function[4])(int,int)={add,sub,multiply,divide};
fun=add;
printf("\nAdd =%d",fun(a,b));
fun=sub;
printf("\nSub=%d",fun(a,b));

fun=multiply;
printf("\nMultiply=%d",fun(a,b));

fun=divide;
printf("\nDivide=%d",fun(a,b));

for(int i=0;i<4;i++)
{
printf("\n%d",function[i](a,b));
}

}

int add(int a, int b)
{
return(a+b);
}
int sub(int a, int b)
{
return(a-b);
}
int multiply(int a,int b)
{
return(a*b);
}
int divide(int a, int b)
{
return(a/b);
}
