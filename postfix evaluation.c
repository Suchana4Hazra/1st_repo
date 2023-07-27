#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int top=-1;
int stack[100];
void push(int d)
{
	top++;
	stack[top]=d;
}
int pop()
{
	int m;
	if(top==-1)
	{
		printf("\n stack is empty.");
		return 0;
	}
	m=stack[top];
	top--;
	return m;
}
int evapostfix(char s[100])
{
	int i,j,op1,op2;
	char temp[5];
	for(i=0;s[i]!='\0';i++)
	{
		j=0;
	while(isdigit(s[i]))
	temp[j++]=s[i++];
	temp[j]='\0';
	if(j!=0)
	push(atoi(temp));
	else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
	{
		op1=pop();
		op2=pop();
		switch(s[i])
		{
			case '+':
				push(op2+op1);
				break;
			case '-':
				push(op2-op1);
				break;
			case '*':
				push(op2*op1);
			    break;
			case '/':
				push(op2/op1);
				break;
		}
	}
	}
	return (pop());
}
main()
{
	char s[100];int ans;
	printf("\n enter any expression: ");
	gets(s);
	ans=evapostfix(s);
	printf("\n ans is: %d",ans);
}
