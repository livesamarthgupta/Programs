#include<bits/stdc++.h>
using namespace std;

/*
	Singly linked list implementation with following functions:
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
	Node* next;
	
	Node(data)
	{
		this->data = data;
		this->next = NULL;
	}
}

class SinglyLinkedList
{
private:
	int size;
	Node* head;
	Node* tail;

public:
	SinglyLinkedList()
	{
		size = 0;
		head = NULL;
		tail = NULL;
	}
	
	void append(int element)
	{
		Node *newnode = new Node(element);
		if(head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		size++;		
	}
	
	void prepend(int element)
	{
		Node *newnode = new Node(element);
		if(head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			newnode->next = head;
			head = newnode;
		}
		size++;
	}
	
	void insert(int index, int element)
	{
		if(index == 0)
			this.preAppend(element);
		else
		{
			Node *newnode = new Node(element);
			Node *temp = head;
			for(int i = 0; i < index - 1; i++)
				temp = temp->next;
			newnode->next = temp->next;
			temp->next = newnode;	
			size++;		
		}	
	}
	
	int remove(int index)
	{
		if(index == 0)
		{
			Node *temp = head;
			int data = head->data;
			head = head->next;
			free(temp);
			size--;
			return data;
		}
		else if(head != NULL)
		{
			Node *temp = head;
			Node *prevtemp;
			for(int i = 0; i < index && temp != NULL; i++)
			{
				prevtemp = temp;
				temp = temp->next;
			}
			int data = temp->data;
			prevtemp->next = temp->next;
			free(temp);
			size--;
			return data;
		}
		return -1;
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
		for(int i = 0; i < size && temp != NULL; i++)
		{
			if(temp->data == element)
				return i;
			else
				temp = temp->next;
		}
		return -1;
	}
}
