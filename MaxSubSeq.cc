#include<iostream>
#define MAXN 10
using namespace std;

int MaxSubseqSum2(int A[], int N);
int main(){
	int seq[MAXN];
	for(int i = 0; i != MAXN; ++i)
		cin >> seq[i];
	cout <<"Max sequence of seq is " << MaxSubseqSum2(seq, MAXN)<< endl;
	return 0;

}

int
MaxSubseqSum2(int A[], int N)
{
	int ThisSum, MaxSum;
	MaxSum = 0;
	for(int i = 0; i != N; ++i)
	{
		ThisSum =0;
		for(int j = i; j != N; ++j)
		{	
			ThisSum += A[j];
			if(ThisSum >= MaxSum)
			MaxSum = ThisSum;
		}
	}
	return MaxSum;

}
