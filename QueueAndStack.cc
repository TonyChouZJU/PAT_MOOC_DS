/*
使用标准c++库实现队列和栈
×*/
#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<vector>
using namespace std;
int main(){
	stack<string> s;
	vector<string> v={"Hello","world","1234"};
	s.push(v[0]);
	s.push(v[1]);
	s.push(v[2]);
	cout << "s的栈顶元素为"<<s.top()<<endl;
	s.pop();
	cout << "pop后的栈顶元素为"<<s.top()<<endl;
	return 0;
}
