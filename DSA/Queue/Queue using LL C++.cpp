#include<bits/stdc++.h>
using namespace std;

/*
	Queue implementation using linked list with following functions:
	void enqueue(int data);
	void dequeue();
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

class Queue
{
	Node *front; 
	Node *rear;
	int size;

public:
	Queue()
	{
		this->front = NULL;
		this->rear = NULL;
		this->size = 0;
	}
	
	void enqueue(int data)
	{
		Node *newnode = new Node(data);
		if(front == NULL)
		{
			front = newnode;
			rear = newnode;
		}
		else
		{
			rear->next = newnode;
			rear = newnode;
		}
		size++;
	}
	
	void dequeue()
	{
		if(front == rear)
		{
			free(front);
			front = NULL;
			rear = NULL;
		}
		else
		{
			Node *temp = front;
			front = front->next;
			free(temp);
		}
		size--;
	}
	
	int peek()
	{
		return front->data;
	}
}
