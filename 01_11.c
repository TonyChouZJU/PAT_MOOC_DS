/*
Maximum Subsequence Sum
pat1007
by zhoudaxia
*/

#include<stdio.h>
int main()
{
	int N,i;
	int a[100000];
	int MaxSum,ThisSum;
	scanf("%d",&N);
	for(i = 0 ; i != N; ++i)
		scanf("%d",a+i);
	MaxSum = ThisSum=0;
	for(i = 0 ; i != N; ++i)
	{
		ThisSum +=a[i];
		if(ThisSum > MaxSum)
			MaxSum = ThisSum;
		else if(ThisSum < 0 )
			ThisSum = 0;
	}
	
	printf("%d", MaxSum);
	return 0;
}
