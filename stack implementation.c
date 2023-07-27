#include<stdio.h>
#define n 5
struct stk
{
	int data[5];
	int top;
};
typedef struct stk STACK;
STACK s;
void push(d)
{
	if(s.top==n-1)
	{
		printf("\n stack is full");
		return ;
	}
	s.top++;
	s.data[s.top]=d;
}
int pop()
{
	int y;
if(s.top==-1)
{
	printf("\n stack is empty ");
	return 0;
	}
y=s.data[s.top];
s.top--;
return y;
}
void list()
{
	int i;
	printf("\n top is:%d",s.top);
	for(i=s.top;i>=0;i--)
	{
		printf("%5d",s.data[i]);
	}
}
main()
{
	int p,ch,a;
	s.top=-1;
	do{
	printf("\n enter 1 for push.\n enter 2 for pop \n enter 3 for exit.\n");
	printf("\n enter your choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\n enter any number: ");
			scanf("%d",&p);
			push(p);
			list();
			break;
		case 2:
		    a=pop();
		    printf("\n popped element is:%d",a);
		    list();
		    break;
		
	}}while(ch!=3);
}
