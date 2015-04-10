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
if(K != 1){
	
	for(i = 1; i != N/K+1; ++i)
	{	
		if(i == 1)
		{
		for(j = 0; j != K-1; ++j)
			printf("%05d %d %05d\n",S[K-j-1],a[S[K-j-1]].data,S[K-j-2]);
		printf("%05d %d %05d\n",S[0],a[S[0]].data,S[K]);
		}
		else
		{		
		for(j = 0; j != K; ++j)
			printf("%05d %d %05d\n",S[i*K-j-1],a[S[i*K-j-1]].data,S[i*K-j-2]);

		}
	}	
	--i;
	for(j = i*K ; j != N-1; ++j)
		printf("%05d %d %05d\n",S[j],a[S[j]].data,a[S[j]].next); 
}
	else//K!=1
	{
	for(j = 0; j != N-1; ++j)
		printf("%05d %d %05d\n",S[j],a[S[j]].data,a[S[j]].next);
	}
	printf("%05d %d %-d\n",S[j],a[S[j]].data,a[S[j]].next);
} 
