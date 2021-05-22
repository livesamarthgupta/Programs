#include<bits/stdc++.h>
using namespace std;

/*
	stack implementation using arrays with following functions:
	void push(int data);
	void pop();
	int peek();
*/

class Stack
{
private:
	vector<int> stack;
	
public:
	
	void push(int data)
	{
		stack.push_back(data);
	}
	
	void pop()
	{
		stack.pop_back();
	}
	
	int peek()
	{
		return stack[stack.size() - 1];
	}
}
