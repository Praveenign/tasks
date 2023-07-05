#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node * next;
};

struct node * createnode()
{
struct node * newnode=(struct node *)malloc(sizeof(struct node));
return(newnode);
}
void node_at_begining(struct node **head,int data)
{
//printf("add=%p\n",head);
struct node * newnode=(struct node *)malloc(sizeof(struct node));
newnode=createnode();
newnode->data=data;
newnode->next=*head;
*head=newnode;
//printf("addi=%p\n",head);
}
void node_at_end(struct node **head,int data)
{
struct node * newnode=(struct node *)malloc(sizeof(struct node));
newnode=createnode();
struct node *last= *head;
if(last==NULL)
{
 newnode->next=last;
newnode->data=data;
*head=newnode; 
}
else
{
while(last->next!=NULL)
{
last=last->next;
}
newnode->data=data;
last->next=newnode;
newnode->next=NULL;
}
}
void print(struct node *head)
{
struct node * currentnode=(struct node *)malloc(sizeof(struct node));
while(head!=NULL)
{
printf("pdata=%p   ",head);
printf("%d\n",head->data);
currentnode=head->next;
head=currentnode;
}
}
void node_at_position(struct node **head,int data,int position)
{
struct node * newnode=(struct node *)malloc(sizeof(struct node));
struct node * currentnode=(struct node *)malloc(sizeof(struct node));
newnode=createnode();
struct node * last =*head;

if(last==NULL)
  {
   newnode->next=last;
  newnode->data=data;
  *head=newnode; 
  }
else
{
for(int i=1;i<position;i++)
{
last=last->next;
printf("head=%p\n",last);
}
/*printf("head=%p\n",head);
 printf("newnode=%p\n",newnode);
  printf("currentnode=%p\n",currentnode);


*/

currentnode=last->next;
newnode->data=data;
last->next=newnode;
newnode->next=currentnode;
/*printf("head=%p\n",head);
printf("newnode=%p\n",newnode);
printf("currentnode=%p\n",currentnode);*/
}
}
void delete_at_position(struct node *head,int position)
{
struct node * newnode=(struct node *)malloc(sizeof(struct node));
struct node * nextnode=(struct node *)malloc(sizeof(struct node));
 
if(head==NULL)
{
printf("Nothing to clear");
}
else
{
for(int i=1;i<position;i++)
  {
  head=head->next;
 // printf("head=%p\n",head);
  }
newnode=head->next;
nextnode=newnode->next;
free(newnode);
head->next=nextnode;
}
 
}
void reverse(struct node **head)
{
struct node * nextnode=NULL;
struct node * currentnode=NULL;
struct node *last=*head;

while(last!=NULL)
{
printf("checki=%p\n",nextnode);
currentnode=last->next;
last->next=nextnode;
nextnode=last;

printf("checkii=%p\n",nextnode);  
//nextnode->next=currentnode;
last=currentnode;
}

*head=nextnode;
}


int main()
{
 struct node * mynode=(struct node *)malloc(sizeof(struct node));
	mynode=NULL;
//	node_at_begining(&mynode,10);
printf("add=%p\n",mynode);
//	node_at_begining(&mynode,20);  
printf("add=%p\n",mynode);
	node_at_end(&mynode,50);
printf("add=%p\n",mynode);
	node_at_end(&mynode,90);
 node_at_end(&mynode,99);
printf("add=%p\n",mynode);
	node_at_position(&mynode,22,2);
printf("add=%p\n",mynode);
	print(mynode);
//delete_at_position(mynode,3);
 printf("After delete\n");
 print(mynode);
reverse(&mynode);
printf("After rev\n");
 printf("add=%p\n",mynode);

print(mynode);
}
