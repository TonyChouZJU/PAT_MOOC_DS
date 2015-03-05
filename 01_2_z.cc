/*
Maximum Subsequence Sum
pat1007
by zhoudaxia
*/

#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int main()
{
	int N,i,j;
	int MaxSum,ThisSum;
	pair<int, int> seq;	
	cin >> N;
	int a[10000];
	for(i = 0; i != N; ++i)
		cin >> a[i];

	int buff=0;
	MaxSum = -1;			//关键思路是将MaxSum初始化为-1,其实只要是[-1,0)区间内的负数即可
	ThisSum =0;
	for(i = 0 ; i != N; ++i)
	{
		ThisSum +=a[i];
		if(ThisSum > MaxSum)
		{
			MaxSum = ThisSum;
//seq.second ,记录最大和序列的最后一个元素
			seq.second = i;
			seq.first = buff;
		}
		else if(ThisSum < 0 )
			{
			ThisSum = 0;
			buff = i+1;
			}
	}
	
	if(MaxSum==-1)			//如果MaxSum还是等于初始值的负数，说明序列中都为负数;只要初始序列中有0或者正数，那么ThisSum便会比初始的MaxSum大，MaxSeq可以向前移动
	{
		MaxSum = 0;
		seq.first = 0;
		seq.second = N-1;
	}
	
	cout << MaxSum <<" " <<a[seq.first] <<" "<<a[seq.second]<<endl;	
}
