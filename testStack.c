/*
利用数组测试stack
*/
#include<stdlib.h>
#include<stdio.h>
//#define MAXSIZE 100
#define MinSize 1

typedef int ElementType;
typedef struct StackNode *Stack;
//使用数组
struct StackNode{
	ElementType *Data;
	int Top;
	int Capacity;
};

//使Stack成为空栈
void
MakeEmpty(Stack S){
	if(S!=NULL)
		S->Top=-1;
}

//创建一个空的Stack
Stack
CreateStack(int MAXSIZE){
	if(MAXSIZE < MinSize){
		printf("MAXSIZE is too small");
		return NULL;
	}
	Stack S;
	S  = (struct node*)malloc(sizeof(struct StackNode));
	S->Data = (ElementType*)malloc(sizeof(ElementType)*MAXSIZE);
	S->Capacity = MAXSIZE;
	MakeEmpty(S);
	return S;
}

//释放Stack空间
void
DeposeStack(Stack S){
	if(S!=NULL){
		free(S->Data);
		free(S);
	}
}

//push一个元素到Stack栈顶中去
void
Push(Stack S, ElementType X){
	if(S->Top!=S->Capacity-1)
		S->Data[++(S->Top)]=X;
	else
		printf("Stack is full");
}

//从Stack中pop一个栈顶元素，并返回该元素
ElementType
Pop(Stack S){
	if(S->Top == -1)
		printf("Stack is empty");
	else
		return S->Data[(S->Top)--];
}

//从Stack中返回栈顶元素
ElementType
Top(Stack S){
	if(S->Top != -1)
		return S->Data[S->Top];
}

int main(){
	Stack s1 = CreateStack(100);
	Push(s1,1);
	Push(s1,2);
	Push(s1,3);
	Push(s1,4);
	printf("%d\n",Pop(s1));
	printf("%d\n",Pop(s1));
	return 0;
}
