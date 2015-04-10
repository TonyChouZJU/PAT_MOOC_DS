/*
使用队列层序遍历二叉树
Mooc ds 3.3
by zhoudaxia
*/
#include<stdlib.h>
#include<stdio.h>

typedef struct node *Queue;
typedef char ElementType;

//使用数组实现
struct node{
	ElementType *data;
	int front;
	int rear;
	int size;			//Queue中元素的实际大小
	int cap;			//Queue的容量是多少
};

int
isEmpty(Queue Q)
{
	return Q->size==0;
}
void
MakeEmpty(Queue Q)
{
	Q->size = 0;
	Q->front = -1;		//front指向实际的最后一个元素
	Q->rear = 0;		//rear指向最后一个元素的后一个元素


}
Queue
CreateQueue(int MaxSize)
{
	Queue Q;
	Q =(struct node *)malloc(sizeof(struct node));
	if(Q==NULL){
		printf("Cannot allocate memory");
		return NULL;
	}
	Q->data = (ElementType *)malloc(sizeof(ElementType)*MaxSize);
	if(Q->data==NULL)
		printf("Cannot allocate memory of data");
	MakeEmpty(Q);
	Q->cap = MaxSize;
	return Q;

}
//使用循环队列
ElementType
DeQueue(Queue Q)
{
	ElementType deq;
	//首先判断队列是否为空
	if(Q->size==0)
		printf("Queue is empty");
	else{
//		if((Q->front+1)%Q->cap==Q->rear)
		--Q->size;
		deq = Q->data[Q->front];
		Q->front = (Q->front+1)%Q->cap;
		return deq;
	}

}

void
EnQueue(Queue Q,ElementType X)
{
	if(Q->size==Q->cap)
		printf("Queue is full");
	else{
		Q->data[(Q->rear+1)%Q->cap]=X;
		Q->rear = (Q->rear+1)%Q->cap;
		++Q->size;
	}

}
int main(){
	int Q_size;
	Queue Q;
	printf("Queue size is:");
	scanf("%d",&Q_size);
	Q= CreateQueue(Q_size);
	EnQueue(Q,'A');
	EnQueue(Q,'B');
	EnQueue(Q,'C');
	EnQueue(Q,'D');
	EnQueue(Q,'F');	
	EnQueue(Q,'G');	
	EnQueue(Q,'I');
	EnQueue(Q,'E');
	while(!isEmpty(Q))
		printf("%c",DeQueue(Q));
	return 0;
}
