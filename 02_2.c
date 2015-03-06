/*
02-2 一元多项式求导
pat-mooc-ds
by zhoudaxia
*/

#include<stdio.h>

int main(){
	int coff[1000];
	int exp[1000];
	int i = 0;
	int size_p;
	while(scanf("%d%d",coff+i,exp+i)!=EOF)
		++i;
	size_p = i;
	
	if( exp[0] == 0)
		printf("0 0");
	else
		for(i = 0; i != size_p; ++i)
		{
			if(exp[i]==0)	break;		//常数项系数
			if(i != 0) printf(" ");
			printf("%d %d",coff[i]*exp[i],exp[i]-1);
		}
	return 0;
}
