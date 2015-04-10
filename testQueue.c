//Mooc ds
//test Circulation Queue
//by zhoudaxia

#include<stdlib.h>
#include<stdio.h>

#define EmptySize 0
typedef struct node *Queue;
typedef int ElementType;
//数组实现循环队列
struct node{
	ElementType *array;
	int front,rear;
	int size;
//	struct node *next;
};

void
MakeEmpty(Queue Q)
{
	Q->front = Q->size -1;
	Q->rear = Q->size -1;		//因为最后一个位置不用

}
Queue
CreateQueue(int MaxSize)
{
	Queue Q;
	Q = (struct node*)malloc(sizeof(struct node));
	if(Q == NULL)
		printf("Queue Cannot alloc memory");
	Q->array = (ElementType *)malloc(sizeof(int)*MaxSize);
	if(Q->array == NULL)
		printf("Array Cannot alloc memory");
	if(MaxSize <2)
		printf("Maxsize must be bigger than 2");
	Q->size = MaxSize;
	MakeEmpty(Q);
	return Q;
}

void
AddQ(Queue Q,ElementType X)
{
	if((Q->rear+1)%Q->size==Q->front)
		printf("Queue is full");
	Q->array[(Q->rear+1)%Q->size] = X;
	Q->rear = (Q->rear+1)%Q->size;
}

ElementType
DeleteQ(Queue Q)
{
	if((Q->front+1)%Q->size ==Q->rear)
		printf("Queue is full");
	Q->front = (Q->front+1)%Q->size;
	return Q->array[Q->front];
}

int main()
{
	Queue q;
	q = CreateQueue(6);
	AddQ(q,1);
	printf("front is %d,rear is %d\n",q->front,q->rear);
	AddQ(q,2);
	printf("front is %d,rear is %d\n",q->front,q->rear);
	AddQ(q,3);
	printf("front is %d,rear is %d\n",q->front,q->rear);
	int tt =DeleteQ(q);
	printf("front is %d,rear is %d\n",q->front,q->rear);
	AddQ(q,4);
	printf("front is %d,rear is %d\n",q->front,q->rear);

}
