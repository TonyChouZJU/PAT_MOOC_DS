/*
建立一棵二叉查找树或二叉搜索树
实现二叉查找数的建立、查找、删除、插入
寻找最大值最小值等常用操作
*/

#include<stdlib.h>
#include<stdio.h>
typedef struct node* PtrNode;
typedef PtrNode BinTree;
typedef int ElementType;

struct node{
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

//递归使二叉树为空
BinTree
MakeEmpty(BinTree T){
	//后序遍历使树free
	if(T!=NULL){
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

//递归或迭代的方法在树中寻找元素X
BinTree
Find(BinTree T, ElementType X){
	//递归版本
	if(T==NULL)
		return NULL;
	if(T->Data ==X) return T;
	else if(X>T->Data) return Find(T->Left,X);
	else return Find(T->Right,X);
	/*迭代版本
	while(T!= NULL){
		if(X==T->Data)	return T;
		else if(X>T->Data) T = T->Right;
		else T = T->Left;
	}
	return NULL;
	*/

}

//递归或迭代的方法在树中查找最大值所在的结点
//注意，最大值一定在右子树的右子树上
BinTree
FindMax(BinTree T){
	if(T==NULL){
		printf("Tree is empty");
		return NULL;	
	}
	if(T->Right ==NULL)
		return T;
	else
		return FindMax(T->Right);

/*迭代
	while(T!=NULL){
		if(T->Right == NULL)
			return T;
		else
			T = T->Right;
	}
	return T;

*/

}

//在二叉树中找最小值的结点
//返回最小值所在的结点
BinTree
FindMin(BinTree T){
//递归
	if(T != NULL){
		if(T->Left == NULL)
			return T;
		else
			return FindMin(T->Left);
	}
	return T;

}
//向二叉树T中插入元素X
//返回二叉树的根结点,注意插入的位置肯定是叶结点
BinTree
Insert(BinTree T, ElementType X){
	if(T==NULL){
		T = (struct node*)malloc(sizeof(struct node));
		T->Data = X;
		//左右子树初始化为NULL
		T->Left = NULL;
		T->Right = NULL;
		return T;
	}
	else{
		if(T->Data == X) 	
			return T;
		else if(T->Data >X) 	
			T->Left = Insert(T->Left,X);
		else			
			T->Right = Insert(T->Right,X);
	}
	return T;
}

//从二叉树中删除元素X
//返回删除之后的根结点
//第一种情况：被删除的为叶子结点，直接将该结点置为NULL
//第二种情况：被删除的结点有一个子结点，则将其父结点的指针指向其孩子结点
//第三种情况：被删除的结点有左右两个子结点，则可以用该结点的左子树的最大值代替该结点的值，再删除左子树的最大值结点
BinTree
Delete(BinTree T,ElementType X){
	BinTree tmpT;
	//在删除之前，先找到X所在结点的位置，不要使用Find函数
	if(T==NULL)
		printf("NO ELEMENT");
	else if(X > T->Data)
		T->Right = Delete(T->Right,X);
	else if(X < T->Data)	
		T->Left = Delete(T->Left,X);
	//现在Ｔ的位置为要删除的结点
	if(T->Left!=NULL &&T->Right!=NULL){
		tmpT = FindMin(T->Right);
		T->Data = tmpT->Data;
		//再将右子树中这个最小值删掉
		T->Right = Delete(T->Right, T->Data);
	}
	else{
	//注意要将删除的结点释放掉
	tmpT = T;
	 if(T->Left == NULL)
		T = T->Right;
	else if(T->Right == NULL)
		T = T->Left;
	free(tmpT);
	}

	return T;
}

int main(){
	BinTree t=NULL;
	t = MakeEmpty(t);
	t = Insert(t,6);
	t = Insert(t,2);
	t = Insert(t,8);
	t = Insert(t,1);
	t = Insert(t,4);
	t = Insert(t,3);

	BinTree tMax = FindMax(t);
	printf("Max is %d",tMax->Data);
	return 0;

}
