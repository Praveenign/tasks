#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void copy_string(char *source,char *destination)
{
while(*source!='\0')
{
*destination=*source;
destination++;
source++;
printf("sour=%p\n",source);
printf("destination=%p\n",destination);
}
}
int main()
{
/**********************************
 * here memory allocarion for char array is first destination then source 
 *for example praveen\0raman
 *so if we access the memory beyond the limit, the vlaue of the next character array will be changed
 ****************************************/
char source[]="praveen";
char destination[]="raman";
printf("source=%s\n",source);
 printf("destination=%s\n",destination);
copy_string(source,destination);
printf("source=%s\n",source);
printf("desig=%s\n",destination);

}

