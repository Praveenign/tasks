#include<stdio.h>
#include<stdbool.h>
#define max_size 100

struct Stack
{
int array[max_size];
int top;
};
struct Queue
{
int array[max_size];
int front;
int rear;
};

void initialization(struct Stack *stack)
{
stack->top=-1;
}

bool isStackempty(struct Stack *stack)
{
printf("stack chk=%d\n",(stack->top==max_size-1));
return(stack->top==max_size-1);
}
void push(struct Stack *stack,int data)
{
	if(isStackempty(stack))
{
printf("Stack overflow\n");
}
else
{
printf("stackid=%d\n",stack->top);
stack->array[++stack->top]=data;
printf("stackid=%d\n",stack->top); 
}
}
int pop(struct Stack *stack)
{
if(stack->top==-1)
{
printf("Stack underflow\n");
return -1;
}
else
{
return(stack->array[stack->top--]);
}
}

void print_stack(struct Stack *stack)
{
for (int i=0;i<=stack->top;i++)
{
printf("stack %d = %d",i,stack->array[i]);
}
}
void queue_init(struct Queue *queue)
{
queue->front=0;
queue->rear=-1;
}

bool isempty(struct Queue *queue)
{
return(queue->front==max_size-1);

}
void enqueue(struct Queue *queue,int data)
{
if(isempty(queue))
{
printf("Queue overflow");
}
else
{
queue->array[++queue->rear]=data;

}
}
int dequeue(struct Queue *queue)
{
 if(queue->front>queue->rear)
{
printf("Nothing in queue");
}
else
{
return(queue->array[queue->front++]);
}
}
void print_queue(struct Queue *queue)
{
for(int i=queue->front;i<=queue->rear;i++)
{

printf("Queue %d = %d\n",i,queue->array[i]);
}
}
int calculator(struct Stack *stack ,char arr[])
{
 int i=0;
printf("%s\n",arr);
while(arr[i]!='\0')
{
if(arr[i]>='0'&&arr[i]<='9')
{
push(stack,arr[i]-'0');
printf("val=%d\n",arr[i]-'0');
}
else
{
int op1=pop(stack);
int op2=pop(stack);
switch(arr[i])
{
case '+':
push(stack,(op1+op2));
break;
case '-':
push(stack,(op1-op2));
break;
case '*':
push(stack,(op1*op2));
break;
case '/':
push(stack,(op1/op2));
break;
default :
printf("Invalid operator");
return -1;
break;
}
}
i++;
}
return(pop(stack));
}
float bank(struct Queue *queue,int arrival_time[],int service_time[],int customer)
{
int waiting_time=0;
int current_time=0;
for(int i=0;i<customer;i++)
{
if(current_time<arrival_time[i])
{
current_time=arrival_time[i];
}
enqueue(queue,current_time);
current_time+=service_time[i];
waiting_time+=(current_time-arrival_time[i]);
printf("c-a=%d\n",(current_time-arrival_time[i]));
printf("Waiting_time= %d\n",waiting_time);
}
printf("Waiting_time= %d\n",waiting_time);

}
int main()
{
char name[]="54*";
int arrival_time[]={2,3,4,5};
int service_time[]={3,2,1,2};
int customer=sizeof(arrival_time)/sizeof(arrival_time[0]);
struct Stack stack;
struct Queue queue;
initialization(&stack);
queue_init(&queue); 
enqueue(&queue,33);
enqueue(&queue,45);
enqueue(&queue,55);
print_queue(&queue);
dequeue(&queue);
print_queue(&queue);
push(&stack,10);
push(&stack,20);
push(&stack,30);
print_stack(&stack);
printf("pop=%d\n",pop(&stack));
print_stack(&stack);
printf("calculate=%d\n",calculator(&stack,name));
printf("avg=%f\n",bank(&queue,arrival_time,service_time,customer));
print_queue(&queue);
}




