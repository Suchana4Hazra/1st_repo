#include<stdio.h>
#define n 5
struct queue
{
int data[5];
int front;
int rear;
};
typedef struct queue QUEUE;
QUEUE s;

int rear_delete()
{
    int m;
if(s.rear==-1)
{
printf("\n queue is empty.");
return 0;
}
m=s.data[s.rear];
if(s.front==s.rear)
{
s.front=-1;
s.rear=-1;
}
else
{
s.rear--;
}
return m;
}

void front_insert(int d)
{
if(s.front==0)
{
printf("\n queue is full");
return;
}
if(s.front==-1)
{
    s.front=0;
    s.rear=0;
}
else
{
s.front--;
}
s.data[s.front]=d;
}

int front_delete()
{
int m;
if(s.front==-1)
{
printf("\n queue is empty");
return 0;
}
m=s.data[s.front];
if(s.front==s.rear)
{
s.front=-1;
s.rear=-1;
}
else
 s.front++;
return m;
}
void rear_insert(int d)
{
if(s.rear==n-1)
{
printf("\n queue is full");
return;
}
if(s.front==-1)
{
s.front=0;
}
s.rear++;
s.data[s.rear]=d;
}

void list()
{int i;
if(s.front!=-1)
{
    printf("\n front=%d  rear=%d",s.front,s.rear);
for(i=s.front;i<=s.rear;i++)
printf("\n %d",s.data[i]);
}
return;
}
main()
{
s.front=-1;
s.rear=-1;
int d,ch;
do{
printf("\n 1.front_insert \n 2.front_delete \n 3.rear_insert \n 4.rear_delete \n 5.exit");
printf("\n enter your choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\n enter any number: ");
scanf("%d",&d);
front_insert(d);
list();
break;

case 2:
d=front_delete();
printf("\n deleted element is: %d",d);
list();
break;

case 3:
printf("\n enter any number: ");
scanf("%d",&d);
rear_insert(d);
list();
break;

case 4:
d=rear_delete();
printf("\n deleted element is: %d",d);
list();
break;
}
}while(ch!=5);
}
