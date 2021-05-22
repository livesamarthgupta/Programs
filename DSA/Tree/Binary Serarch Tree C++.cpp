#include<bits/stdc++.h>
using namespace std;

/*
	Binary Search Tree implementation using linked list with following functions:
	void insert(int data);
	void remove(int data);
	int lookup(int data);
*/

class Node
{
public:
	int data;
	Node *left;
	Node *right;
	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
}

class BST
	Node *root;

public:
	BST()
	{
		this->root = NULL;
	}
	
	void insert(int data)
	{
		Node *newnode = new Node(data);
		if(root == NULL)
			root = newnode;
		else
		{
			Node *current = root;
			while(true)
			{
				if(data < current->data)
				{
					if(current->left == NULL)
					{
						current->left = newnode;
						break;
					}
					else
						current = current->left;
				}
				else if(data > current->data)
				{
					if(current->right == NULL)
					{
						current->right = newnode;
						break;
					}
					else
						current = current->right;
				}
			}
		}
	}
	
	void remove(int data)
	{
		
	}
	
	bool lookup(int data)
	{
		if(!root)
			return false;
		else
		{
			Node *current = root;
			while(current)
			{
				if(data == current->data)
					return true;
				else if(data < current->data)
					current = current->left;
				else if(data > current->data)
					current = current->right;
			}
			return false;
		}
	}
	
}
