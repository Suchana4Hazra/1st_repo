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
	if(s.rear==n-1)
	{
		printf("\n the queue is full.");
		return;
	}
	if(s.front==-1)
	{
	s.front=0;
}
	s.rear++;
	s.data[s.rear]=d;
}
int pop()
{
	int m;
	if(s.front==-1)
	{
		printf("\n queue is empty.");
		return 0;
	}
	m=s.data[s.front];
	if(s.rear==s.front)
	{
		s.front=-1;
		s.rear=-1;
	}
	else
	{
		s.front++;
	}
	return m;
}
void list()
{
	int i;
	if(s.front!=-1)
	{
		printf("\n front=%d  rear=%d",s.front,s.rear);
		for(i=s.front;i<=s.rear;i++)
		{
			printf("\n %d",s.data[i]);
		}
	}
}
main()
{
	int ch,d;
	s.rear=-1;
	s.front=-1;
	do{
		printf("\n 1.push \n 2.pop \n 3.exit");
		printf("\n enter ur choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n enter any number: ");
				scanf("%d",&d);
				push(d);
				list();
				break;
			case 2:
				d=pop();
				printf("\n popped element:%d",d);
				list();
				break;		
		}
	}while(ch!=3);	
}
