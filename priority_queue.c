#include<stdio.h>
#define n 5
struct queue
{
	int data[5];
	int prio[5];
	int front;
	int rear;
};
typedef struct queue QUEUE;
QUEUE s;
void insert(int d,int r)
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
	s.prio[s.rear]=r;
}
int priority()
{
	int i,p,m;
	m=s.prio[s.front];
	p=s.front;
	for(i=s.front+1;i<=s.rear;i++)
	{
		if(s.prio[i]>m)
		{
			m=s.prio[i];
			p=i;
		}
	}
	return (p);
}
int del()
{
	int pos,x,i;
	if(s.front==-1)
	{
		printf("\n queue is empty");
		return 0;
	}
	if(s.front==s.rear)
	{
		x=s.data[s.front];
		s.front=-1;
		s.rear=-1;
	}
	else
	{
		pos=priority();
		x=s.data[pos];
		for(i=pos;i>s.front;i--)
		{
			s.data[i]=s.data[i-1];
			s.prio[i]=s.prio[i-1];
		}
		s.front++;
	}
	return x;
}
void list()
{
	int i;
	printf("\n front=%d  rear=%d",s.front,s.rear);
	for(i=s.front;i<=s.rear;i++)
	{
		printf("\n %d(%d)",s.data[i],s.prio[i]);
	}
	return;
}
main()
{
	int ch,d,r;
	s.front=-1;
	s.rear=-1;
	do{
		printf("\n 1.insert \n 2.delete \n 3.exit");
		printf("\n enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n enter any number and its priority: ");
				scanf("%d %d",&d,&r);
				insert(d,r);
				list();
				break;
			case 2:
				d=del();
				if(d!=0)
				{
					printf("\n deleted elemnt: %d",d);
					list();
				}
				break;
		}}
		while(ch!=3);
}
