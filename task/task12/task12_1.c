#include<stdio.h>

typedef union endian_test
{
char array[4];
unsigned int data;
}Union;
unsigned int swap(unsigned int data)
{
int i=0;
unsigned int temp[4]={0};
unsigned int temp2=0;
while(i<4)
{
temp[i]=((data>>(i*8))&0xFF);
printf("data=%x\n",temp[i]);
i++;
}
temp2=((temp[0]<<24)|(temp[1]<<16)|(temp[2]<<8)|(temp[3]));
//printf("%x\n",temp2);
return temp2;

}
int main()
{;
Union obj;
obj.data=0x01020304;
int data=0x01020304;
printf("data=%x\n",data);
printf("data=%x\n",swap(data));
printf("%x",obj.array[0]);
}
