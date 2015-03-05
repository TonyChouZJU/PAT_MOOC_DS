/*
Maximum Subsequence Sum
pat1007
by zhoudaxia
*/

#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	int N,i;
	int MaxSum,ThisSum;
	scanf("%d",&N);
	int a[100000];
	for(i = 0; i != N; ++i)
		scanf("%d",a+i);

	MaxSum = ThisSum =0;
	for(i = 0 ; i != N; ++i)
	{
		ThisSum +=a[i];
		if(ThisSum > MaxSum)
			MaxSum = ThisSum;
		else if(ThisSum < 0 )
			ThisSum = 0;
	}
	
	cout << MaxSum <<endl;	
	return 0;
}
