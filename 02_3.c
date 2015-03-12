/*
求前缀表达式的值
pat Mooc ds
by zhoudaxia
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node *Stack;
typedef double ElementType;
struct node{
	ElementType Element;
	struct node *next;
};

int
isEmpty(Stack S)
{
	return S->next == NULL;
}

ElementType
pop(Stack S)
{
	if(isEmpty(S))
		printf("Stack is empty");
	else
	{
		Stack tmpS;
		ElementType tmpE;
		tmpS = S->next;
		S->next = tmpS->next;
		tmpE = tmpS->Element;
		free(tmpS);
		return tmpE;
	}
}	

void
MakeEmpty(Stack S)
{
	if(S == NULL)
		printf("Use CreateStack first");
	else
		while(!isEmpty(S))
			pop(S);
}

Stack
CreateStack()
{
	Stack tmpS;
	tmpS = (struct node*)malloc(sizeof(struct node));
	if(tmpS == NULL)
		printf("Out of Space");
	tmpS->next = NULL;
	MakeEmpty(tmpS);
	return tmpS;
}

void
push(Stack S,ElementType X)
{
	Stack tmpS;
	tmpS = (struct node*)malloc(sizeof(struct node));
	tmpS->Element = X;
	tmpS->next = S->next;
	S->next = tmpS;
}

int
isOperator(double c)
{
	return (c==(double)'+'||c==(double)'-'||c==(double)'*'||c==(double)'/');
}

double
ComputeTwo(double c1,double c2,double operator)
{
	double result;
	switch((int)operator)
	{
	  case '+': result = c1+c2;break;
	  case '-': result = c1-c2;break;
	  case '*': result = c1*c2;break;
	  case '/': result = c1/c2;break;
	}
	return result;
}

double
getNum(char s[])
{
	int i = 0;
	int j = 0;
	double sum = 0;
	double chu =1;
	double sum_d = 0;
	for(i = 0; i != strlen(s);++i)
		if(*(s+i)=='.')
			break;
	if(i == strlen(s))
	{
		if(*s=='+'||*s=='-')
			j++;
		for(; j != strlen(s); ++j)
			sum = 10*sum + *(s+j)-'0';
		if(*s=='-')
			sum = -sum;
	}
	else
	{
		if(*s=='+'||*s=='-')
			j++;
		for(; j != i ; ++j)
			sum = 10 * sum + *(s+j)-'0';
		for(j = i+1; j != strlen(s); ++j)
			{
			chu = chu*10;
			sum_d = sum_d + (*(s+j)-'0')/chu;
			}
		sum = sum +sum_d;
		if(*s=='-')
			sum = -sum;
	}
	return sum;
}
int main()
{
	double c[30],c1,c2;
	char s[30];
	int i=0;
	int j;
	double exp = 0;		//save the value of the expression
	Stack S;
	S = CreateStack();
	while(scanf("%s",s)!=EOF)
		{
		if(strlen(s)==1)
			{if(*s=='+'||*s=='-'||*s=='*'||*s=='/')
				c[i]=(double)(*s);
			else
				c[i]=(double)(*s-'0');
			}
		else
			c[i] = getNum(s);	
		++i;			
		}	
	--i;			//关键
	for(j=i; j!=-1; --j)
	{
	//	printf("%c",c[j]);
		if(!isOperator(c[j]))
			push(S,c[j]);
		else
		{
			c1 = pop(S);
			c2 = pop(S);
			if(c[j]=='/'&&c2==0)
				{
					printf("ERROR");
					return 0;
				}
				
			push(S,ComputeTwo(c1,c2,c[j]));
		}
	}
	exp = pop(S);
	
	printf("%.1f",exp);
	return 0;
}
