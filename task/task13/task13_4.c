#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void secretmsg()
{
printf("secret msg\n");
}
void vulnerable(char *name)
{
char name2[10];
strcpy(name2,name);
printf("completed");
}
int main(int arg,char **arv)
{
void (*ptr)()=&secretmsg;
printf("add=%p\n",ptr);
printf("chaeck=%s\n",arv[1]);
vulnerable(arv[1]);
}
