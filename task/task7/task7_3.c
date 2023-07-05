#include<stdio.h>
enum calculator
{
add,
sub,
multiply,
divide};
int sum(int,int);
int subtract(int,int);
int Multi(int,int);
int Divide(int,int);
int calculate(int ,int ,enum calculator );
int (*func[])(int,int)={sum,subtract,Multi,Divide};
unsigned int a=0,b=0;
int main()
{
printf("Enter the number1");
scanf("%d",&a);
printf("Entr the number2");
scanf("%d",&b);
enum calculator function;
printf("Add=%d\n",calculate(a,b,add));
printf("Sbtract=%d\n",calculate(a,b,sub)); 
printf("Multiple=%d\n",calculate(a,b,multiply)); 
printf("Divide=%d\n",calculate(a,b,divide)); 


}
int sum(int a, int b)
{
return(a+b);
}
int subtract(int a, int b)
{
return(a-b);
}
int Multi(int a,int b)
{
return(a*b);
}
int Divide(int a, int b)
{
return(a/b);
}
int calculate(int a,int b,enum calculator function)
{

 return(func[function](a,b));


}
