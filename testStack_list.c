/*
利用数组测试stack
*/
#include<stdlib.h>
#include<stdio.h>
//#define MAXSIZE 100
#define MinSize 1

typedef int ElementType;
typedef struct StackNode *Stack;
//使用链表
struct StackNode{
	ElementType Data;
	Stack next;
};

//使Stack成为空栈
void
MakeEmpty(Stack S){
	if(S!=NULL)
		S->next=NULL;
}

//创建一个空的Stack
Stack
CreateStack(){
	Stack S = (struct StackNode*)malloc(sizeof(struct StackNode));
	MakeEmpty(S);
	return S;
}

//释放Stack空间
void
DeposeStack(Stack S){
	if(S!=NULL)
		free(S);
}

//push一个元素到Stack栈顶中去
void
Push(Stack S, ElementType X){
	Stack tmpS= (struct StackNode*)malloc(sizeof(struct StackNode));
	if(tmpS!=NULL){
		tmpS->Data = X;
		tmpS->next = S->next;
		S->next = tmpS;
	}
	else
		printf("Cannot alloc a stack");
}

//从Stack中pop一个栈顶元素，并返回该元素
ElementType
Pop(Stack S){
	if(S->next ==NULL)
		printf("Stack is empty");
	else{
		Stack tmpS = S->next;
		ElementType tmpX=tmpS->Data;
		S->next = tmpS->next;
		free(tmpS);
		return tmpX;
	}
}

//从Stack中返回栈顶元素
ElementType
Top(Stack S){
	if(S->next!=NULL)
		return S->next->Data;
}

int main(){
	Stack s1 = CreateStack();
	Push(s1,1);
	Push(s1,2);
	Push(s1,3);
	Push(s1,4);
	printf("%d\n",Pop(s1));
	printf("%d\n",Pop(s1));
	return 0;
}
