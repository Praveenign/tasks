#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 10
struct hash_node
{
char *key;
int value;
};
int hash_key(char *key)
{
int sum=0;
while(*key!='\0')
{
sum=sum+*key;
key++;
}
return(sum%size);
}
struct hash_node**createtable()
{
struct hash_node ** table=(struct hash_node**)malloc(sizeof(struct hash_node*)*size);
for(int i=0;i<size;i++)
  {
  table[i]=NULL;
  }
return table;

}
struct hash_node * createnode(char *key,int data)
{
//printf("key=%s\n",key);
 // printf("data=%d\n",data);


struct hash_node * new=(struct hash_node*)malloc(sizeof(struct hash_node));
//printf("add=%p\n",new);
new->value=data;
new->key=(char*)malloc(sizeof(key));
strcpy(new->key,key);
//printf("key=%s\n",key);
//printf("data=%d\n",data);

return new;
}

void insert(struct hash_node **table,char *key,int data)
{
//printf("key=%s\n",key);
// printf("data=%d\n",data);

struct hash_node *new;
new=createnode(key,data);
//printf("add=%p\n",new);
int index=hash_key(key);
while(table[index]!=NULL)
{
index=(index+1)%size;
}
table[index]=new;

}

void print(struct hash_node **table)
{
for(int i=0;i<size;i++)
{
if(table[i]!=NULL)
{
 printf("val=%d\n",table[i]->value);
 printf("key=%s\n",table[i]->key);
i++;
}
}
}
void delete(struct hash_node **table,char *key)
{
int index=hash_key(key);
while(table[index]!=NULL)
{
if(strcmp(table[index]->key,key)==0)
{
free(table[index]);
table[index]=NULL;
break;
}
index=(index+1)%size;
}
}
int  search(struct hash_node**table,char *key)
{
int index=hash_key(key);
  while(table[index]!=NULL)
  {
  if(strcmp(table[index]->key,key)==0)
  {
  return(table[index]->value);
 }
  index=(index+1)%size;
  }
return -1;
}

int main()
{
struct hash_node ** table=createtable();
//printf("addrss=%p\n",table);
insert(table, "praveen ",20);
insert(table, "naveen",87);

print(table);
printf("search=%d\n",search(table,"naveen"));
delete(table,"naveen");
print(table);
}
