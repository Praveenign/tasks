#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void print_string(char *p)
{
printf("%s\n",p);
}
int main()
{
char * name=NULL;
char * name1="HELLO";
char *p="world";
//p=name1;
//print_string(name);
print_string(name1);
print_string(p);
/********************************
 * only dynamically allocated memory will be free using the free function
 * it check for address which is created by malloc or calloc during the free function
 * *************************************/
//free(p);  // not possible
print_string(p);
return 0;
}
