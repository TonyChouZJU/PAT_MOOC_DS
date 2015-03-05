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
	int flag = 0;				//记录是否所有输入都为负数
	pair<int, int> seq;	
	cin >> N;
	int a[10000];
	for(i = 0; i != N; ++i)
		cin >> a[i];

	MaxSum = ThisSum =0;
	for(i = 0 ; i != N; ++i)
	{
		ThisSum +=a[i];
		if(a[i]>=0)
			flag =1;
		if(ThisSum > MaxSum)
		{
			MaxSum = ThisSum;
//seq.second ,记录最大和序列的最后一个元素
			seq.second = i;
		}
		else if(ThisSum < 0 )
			ThisSum = 0;
	}
	
//比较笨的方法，从seq。second往前找和为MaxSum的下标
	int tmpSum=0;
	for(i = seq.second; i != -1; --i)
	{	tmpSum +=a[i];
		if(tmpSum==MaxSum)
			break;
	}
	seq.first = i;

	if(MaxSum==0)
	{
	if(flag == 0)		//所有输入都为负数
	cout <<"0 " <<a[0]<<" "<<a[N-1]<<endl;
	else
	cout <<"0 0 0"<<endl;
	}
	
	else
	cout << MaxSum <<" " <<a[seq.first] <<" "<<a[seq.second]<<endl;	
}
