/*
Maximum Subsequence Sum
pat1007
by zhoudaxia
*/

#include<iostream>
#include<stdio.h>

using namespace std;

int MaxSubseq(int A[],int N)
{
	int MaxSum,ThisSum;
	MaxSum = ThisSum=0;
	int i;
	for(i = 0 ; i != N; ++i)
	{
		ThisSum +=A[i];
		if(ThisSum > MaxSum)
			MaxSum = ThisSum;
		else if(ThisSum < 0 )
			ThisSum = 0;
	}
	
	cout << MaxSum;
	return 0;
}

int main()
{
	int N,i;
	int a[10000];
	cin >> N;
	for(i = 0 ; i != N; ++i)
		cin>>a[i];
	MaxSubseq(a,N);
	return 0;
}
