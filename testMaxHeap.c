//创建并测试最大堆
//堆是一种优先队列

#include<stdlib.h>
#include<stdio.h>
#define MAXDATA 100000
typedef struct node* MaxHeap;
typedef int ElementType;

struct node{
	ElementType *Data;
	int Size;
	int Capacity;
};

//判断最大堆是否为空
int
isEmpty(MaxHeap H){
	return H->Size;
}

//判断最大堆是否满
int
isFull(MaxHeap H){
	return H->Size == H->Capacity;
}

//建立一个空的最大堆
MaxHeap
CreateMaxHeap(int MaxSize){
	MaxHeap H = (struct node*)malloc(sizeof(struct node));
	H->Data = (ElementType *)malloc(sizeof(ElementType)*MaxSize);
	H->Capacity = MaxSize;
	H->Size = 0;
	H->Data[0] = MAXDATA;
	return H;
}

//将元素X插入到最大堆中
//返回插入之后的最大堆
MaxHeap
Insert(MaxHeap H, ElementType X){
	if(isFull(H)){
		printf("Heap is Full");
		return H;
	}
	else{
	//这里将X先插入到最后一个位置
	//也可以最后一个位置先不放，即parent=++H->Size;
	H->Data[++H->Size]=X;
	int parent = H->Size;
	for(;H->Data[parent/2] < X; parent = parent/2)
		H->Data[parent]=H->Data[parent/2];
	H->Data[parent] = X;
	}
	return H;
}

//删除最大堆中的最大元素
//返回该元素的值,堆变成删除后的堆
ElementType
DeleteMax(MaxHeap H){
	ElementType MaxH,tmpX;
	int parent,child;
	if(isEmpty(H)){
		printf("Heap is Empty");
	}
	else{
	//从根结点开始，从上往下过滤下层结点
		MaxH = H->Data[1];
		tmpX = H->Data[H->Size--];
		for(parent = 1;parent*2 <= H->Size; parent =child){
			child = parent*2;
			if((child != H->Size)&&(H->Data[child]<H->Data[child+1]))
				child ++;		//child指向左右子结点中较大的那个
			if(tmpX >= H->Data[child])	break;
			else		//移动tmpX到下一层
				H->Data[parent]=H->Data[child];
		}
	}

}

int main(){
	MaxHeap mh=CreateMaxHeap(100);
	mh = Insert(mh, 83);
	printf("The root num is %d\n",mh->Data[1]);	
	mh = Insert(mh, 72);
	mh = Insert(mh, 91);
	mh = Insert(mh, 79);
	mh = Insert(mh, 43);
	mh = Insert(mh, 87);
	mh = Insert(mh, 38);
	int i;
	for( i = 0; i != mh->Size; ++i)
		printf("Data[%d] is %d\n",i,mh->Data[i]);	
	return 0;
}
