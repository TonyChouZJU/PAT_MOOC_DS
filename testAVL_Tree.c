//实现平衡二叉查找树的建立
//插入，查找，寻找最大值、最小值，删除等操作

#include<stdlib.h>
#include<stdio.h>
#include<math.h>
typedef struct node *AVLTree;
typedef int ElementType;

struct node{
	ElementType Data;
	AVLTree Left;
	AVLTree Right;
	int Height;	
};

//释放二叉树中每一个对象
AVLTree
MakeEmpty(AVLTree T){
	if(T!=NULL){
		//后序遍历
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return T;

}

//在ＡＶＬ树中查找对象Ｘ
//返回该结点，和普通二叉树相同
AVLTree
Find(AVLTree T, ElementType X){
//递归
	if(T!=NULL){
		if(T->Data > X)
			return Find(T->Left,X);
		else if(T->Data < X)
			return Find(T->Right,X);
	}
	else
		printf("NO X in AVLTREE"); 

	return T;
/*迭代
//注意 不要将T!=X放在while的条件中去，这样每次都要比较
	if(T!=X)
	while(T->Data != X){
		if(T->Data > X)
			T = T->Left;
		else if(T->Data < X)
			T = T->Right;
	}
	return T;

*/
}

//ＡＶＬ树中找最大值
//返回最大值所在的结点
AVLTree
FindMax(AVLTree T){
//递归
	if(T!=NULL){
		if(T->Right==NULL)
			return T;
		else
			return FindMax(T->Right);
	}
	else
		return T;

/*迭代
	if(T!=X)
	while(T->Right!=NULL)
		T = T->Right;
	return T;

*/
}

AVLTree
FindMin(AVLTree T){
	if(T!=NULL){
		if(T->Left == NULL)
			return T;
		else
			return FindMin(T->Left);
	}
	return T;

}
//自定义Max函数
ElementType
max(ElementType A, ElementType B){
	return (A>B)?A:B;
}
//返回树的高度
int 
Height(AVLTree T){
	if(T==NULL)
		return -1;
	else
		return T->Height;
}

//AVL树中最重要的操作
//AVL的插入操作
//先实现非平衡版本的插入操作
AVLTree
Insert(AVLTree T, ElementType X){
	if(T==NULL){
		T = (struct node*)malloc(sizeof(struct node));
		T->Data = X;
		T->Left = NULL;
		T->Right= NULL;
		T->Height =0;
	}
	else{
	if(T->Data > X)
		T->Left = Insert(T->Left,X);
	else if(T->Data <X)
		T->Right= Insert(T->Right,X);
	T->Height = max(Height(T->Left),Height(T->Right))+1;
	}
	return T;
}
//左单旋
AVLTree
SingleRotatewithLeft(AVLTree A){
	AVLTree B;
	B = A->Left;
	A->Left = B->Right;
	B->Right = A;

	//更新ＡＢ的高度
	A->Height = max(Height(A->Left),Height(A->Right))+1;
	B->Height = max(Height(B->Left),Height(A))+1;
	return B;
}
//右单旋
AVLTree
SingleRotatewithRight(AVLTree A){
	AVLTree B;
	B = A->Right;
	A->Right = B->Left;
	B->Left = A;

	//更新ＡＢ的高度
	A->Height = max(Height(A->Left),Height(A->Right))+1;
	B->Height = max(Height(B->Right),Height(A))+1;
	return B;
}

AVLTree
DoubleRotatewithLeft(AVLTree A){
	A->Left = SingleRotatewithRight(A->Left);
	return SingleRotatewithLeft(A);
}

AVLTree
DoubleRotatewithRight(AVLTree A){
	A->Right = SingleRotatewithLeft(A->Right);
	return SingleRotatewithRight(A);
}
//实现平衡版本的插入操作
AVLTree
AvlInsert(AVLTree T, ElementType X){
	if(T==NULL){
		T = (struct node*)malloc(sizeof(struct node));
		T->Data = X;
		T->Left = NULL;
		T->Right = NULL;
		T->Height = 0;
	}
	else{
		//先进行插入操作,插入完成后比较左右子树的高度差
		if(T->Data >X){
			T->Left = AvlInsert(T->Left,X);
			if(Height(T->Left)-Height(T->Right)==2)
			//如果插入的位置是在左子树的左边，则进行LL单旋
				if(X < T->Left->Data)
					T=SingleRotatewithLeft(T);
				else
					T=DoubleRotatewithLeft(T);
		}
		else{
			T->Right = AvlInsert(T->Right,X);
			if(Height(T->Right)-Height(T->Left)==2)
			//如果插入的位置是在右子树的右边，则进行RR单旋
				if(X > T->Right->Data)
					T=SingleRotatewithRight(T);
				else
					T=DoubleRotatewithRight(T);
		}
	}
	T->Height = max(Height(T->Left),Height(T->Right))+1;
	return T;
}

int main(){
	AVLTree t = NULL;
	t = AvlInsert(t,1);
	printf("AVL tree's height is %d\n",Height(t));
	t = AvlInsert(t,2);
	printf("AVL tree's height is %d\n",Height(t));
	t = AvlInsert(t,3);
	printf("AVL tree's height is %d\n",Height(t));
	t = AvlInsert(t,4);
	printf("AVL tree's height is %d\n",Height(t));
	t = AvlInsert(t,5);
	printf("AVL tree's height is %d\n",Height(t));
	t = AvlInsert(t,6);
	printf("AVL tree's height is %d\n",Height(t));
	printf("The root of the avl_tree is %d",t->Data);
	return 0;
}
