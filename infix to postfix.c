#include<stdio.h>
char stack[100];
int top=-1;
void push(int d)
{
	top++;
	stack[top]=d;
}
char pop()
{
	char m;
	if(top<0)
	{
		printf("\n stack is empty");
		return '\0';
	}
	m=stack[top];
	top--;
	return (m);
}
int precedence(char a)
{
	if(a=='^')
	return 1;
	else if(a=='*' || a=='/')
	return 2;
	else if(a=='+' || a=='-')
	return 3;
	else if(a=='(' || a==')')
	return 4;
}
int checkpre(char a,char b)
{
	int n1,n2;
	n1=precedence(a);
	n2=precedence(b);
	if(n1<=n2 && a!='(' && b!=')')
	return 1;
	else
	return 0;	
}
void postfix(char str[100])
{
	char c,v,p[100];
	int i,j=0,g;
	for(i=0;str[i]!='\0';i++)
	{
	c=str[i];
	if((c>=65 && c<=90) || (c>=97 && c<=122))
	{
		p[j]=c;
		j++;
	}
	else if(c=='(')
	{
		push(c);
	}
	else if(c==')')
	{
		while(1)
		{
			v=pop();
			if(v=='(' || v=='\0')
			break;
			else
			{
				p[j]=v;
				j++;
			}
		}
	}
		else if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')	
		{
			while(top!=-1)
			{
				v=pop();
				if(checkpre(v,str[i])==1)
				{
					p[j]=v;
					j++;
				}
				else
				{
				push(v);
				break;
			}
		}
		push(c);
	}
//	p[j]='\0';
	printf("\n");
	printf("%c\t",str[i]);
	for(g=0;g<=top;g++)
	{
		printf("%c",stack[g]);
	}
	printf("\t");
	puts(p);
	getche();
		}
			while(top!=-1)
			{
				v=pop();
				p[j]=v;
				j++;
			}
			p[j]='\0';
			printf("\t\n");
			puts(p);
			getche();
			return;
}
main()
{
	char str[100];
	printf("\n enter any string: ");
	gets(str);
	postfix(str);
	printf("\n postfix: ");
}
