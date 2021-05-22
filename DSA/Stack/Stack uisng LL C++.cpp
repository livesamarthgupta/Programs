#include<bits/stdc++.h>
using namespace std;

/*
	stack implementation using linked list with following functions:
	void push(int data);
	void pop();
	int peek();
*/

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
}

class Stack
{
private:
	Node *top;
	int size;
	Stack()
	{
		this->top = NULL;
		this->size = 0;
	}
	
	void push(int data)
	{
		Node *newnode = new Node(data);
		if(top == NULL)
		{
			top = newnode;
			size++;
		}
		else
		{
			newnode->next = top;
			top = newnode;
			size++;
		}
	}
	
	void pop()
	{
		if(top != NULL)
		{
			Node *temp = top;
			top = top->next;
			free(temp);
			size--;
		}
	}
	
	int peek()
	{
		if(top != NULL)
			return top->data;
	}
}
