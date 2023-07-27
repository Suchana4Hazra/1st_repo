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
void push(int d)
{
	if(s.front==(s.rear+1)%n)
	{
		printf("\n queue is full");
		return;
	}
	if(s.front==-1)
	{
		s.front=0;
	}
	s.rear=(s.rear+1)%n;
	s.data[s.rear]=d;
}
int pop()
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
	s.front=(s.front+1)%n;
	return m;
}
void list()
{
	int i;
	if(s.front!=-1)
	{
		printf("\n front=%d rear=%d",s.front,s.rear);
		for(i=s.front;i!=s.rear;i=(i+1)%n)
		{
			printf("\n %d",s.data[i]);
		}
		printf("\n %d",s.data[s.rear]);
	}
	return;
}
main()
{
	s.front=-1;
	s.rear=-1;
	int d,ch;
	do{
		printf("\n 1.push \n 2.pop \n 3.exit ");
		printf("\n enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n enter any no.: ");
				scanf("%d",&d);
				push(d);
				list();
				break;
			case 2:
				d=pop();
				printf("\n popped element is: %d",d);
				list();
				break;
		}
	}while(ch!=3);
}
