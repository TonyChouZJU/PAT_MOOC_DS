/*
02_1 Reversing Linked List
pat_mooc_ds
by zhoudaxia
*/
#include<stdio.h>

int main(){
	int first_node,N,K;
	int i,j;
	int tmp_add,tmp_data,tmp_next;
	scanf("%d%d%d",&first_node,&N,&K);
	
	struct node{
		int next;
		int data;

	}a[100000];
	for(i = 0; i != N; ++i)
	{
		scanf("%d%d%d",&tmp_add,&tmp_data,&tmp_next);
		a[tmp_add].data = tmp_data;
		a[tmp_add].next = tmp_next;
	}
	int S[N];
	tmp_add = first_node;
	i = 0;
	while(tmp_add != -1){
		S[i++] = tmp_add;
		tmp_next = a[tmp_add].next;
		tmp_add = tmp_next;
	}
	//K!=1
	int tmp;
	for(i = 0 ; i != N/K; ++i)
	{	
		tmp = i*K;
		for(j= K-1; j != 0; --j)
			printf("%05d %d %05d\n",S[tmp+j],a[S[tmp+j]].data,S[tmp+j-1]);
		
		if(a[S[tmp+K-1]].next == -1)		//N=K
			printf("%05d %d %-d\n",S[tmp],a[S[tmp+j]].data,a[S[tmp+K-1]].next);
		else
			printf("%05d %d %05d\n",S[tmp],a[S[tmp+j]].data,a[S[tmp+K-1]].next);
	}
	for(j = i*K; j!=N;++j){
		if(j!=N-1)
			printf("%5d %d %05d\n",S[j],a[S[j]].data,S[j+1]);
		else
			printf("%5d %d %-d\n",S[j],a[S[j]].data,a[S[j]].next);
	}
} 
