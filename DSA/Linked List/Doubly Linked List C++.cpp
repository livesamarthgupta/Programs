#include<bits/stdc++.h>
using namespace std;

/*
	Doubly linked list implementation with following functions:
	void append(int element);
	void prepend(int element);
	void insert(int index, int element);
	int remove(int index);
	void display();
	int search(ine element);
*/

class Node
{
public:
	int data;
	Node *next;
	Node *prev;
	
	Node(int data)
	{
		this->data = data;
		this->next = NULL
		this->prev = NULL;
	}
}

class DoublyLinkedList
{
private:
	int size;
	Node *head;
	Node *tail;
	
public:
	
	DoublyLinkedList()
	{
		size = 0;
		head = NULL;
		tail = NULL;
	}
	
	void append(int data)
	{
		Node *newnode = new Node(data);
		newnode->prev = tail;
		tail->next = newnode;
		tail = newnode;
		size++;
	}
	
	void prepend(int data)
	{
		Node *newnode = new Node(data);
		if(head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			newnode->next = head;
			head->prev = newnode;
			head = newnode;
		}
		size++;
	}
	
	void insert(int index, int data)
	{
		Node *newnode = new Node(data);
		if(index == 0)
			prepend(data);
		else
		{
			Node *temp = head;
			for(int i = 0; i < index && temp->next != NULL; i++)
				temp = temp->next;
			newnode->next = temp->next;
			temp->next->prev = newnode;
			newnode->prev = temp;
			temp->next = newnode;
		}
		size++;
	}
	
	int remove(int index)
	{
		Node *temp = head;
		if(index == 0)
		{
			Node *freeNode = head;
			head = head->next;
			head->prev = NULL:
			int res = freeNode->data;
			free(freeNode);
			size--;
			return res;
		}
		else if(index == size -1)
		{
			Node *freeNode = tail;
			tail = tail->prev;
			tail->next = NULL;
			int res = freeNode->data;
			free(freeNode);
			size--;
			return res;
		}
		else
		{
			for(int i = 0; i < index && temp->next != NULL; i++)
				temp = temp->next;
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			int res = temp->data;
			free(temp);
			size--;
			return res;
		}
	}
	
	void display()
	{
		Node *temp = head;
		while(temp != NULL)
		{
			cout<<temp->data;
			temp = temp->next;
		}
	}
	
	int search(int element)
	{
		Node *temp = head;
		int i = 0;
		while(temp != NULL)
		{
			if(temp->data == element)
			{
				return i;
			}
			i++;
			temp = temp->next;
		}
		return -1;
	}
	
}

