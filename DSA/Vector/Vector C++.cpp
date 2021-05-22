#include<bits/stdc++.h>

using namespace std;

/*
	vector implementation with following functions:
	void push(data);
	void push(index, data);
	int get(index);
	int pop();
	int pop(index);
	int size();
	int getCapacity();
	void print();
*/

class myVector
{
private:
	int capacity;
	int *array;
	int size;

public:
	myVector()
	{
		*array = new int[2];
		capacity = 2;
		size = 0;
	}
	
	void push(int data)
	{
		if(size == capacity)
		{
			int *temp = new int[capacity * 2];
			for(int i = 0; i < capatiy; i++)
			{
				temp[i] = array[i];
			}
			delete[] array;
			capacity *= 2;
			array = temp;
		} 
		array[size] = data;
		size++;
	}
	
	void push(int index, int data)
	{
		array[index] = data;
	}
	
	int get(int index)
	{
		return array[index];
	}
	
	int pop()
	{
		int ele = array[size - 1];
		size--;
		return ele;
	}
	
	int pop(int index)
	{
		if(index < size)
		{
			int ele = array[index];
			for(int i = index; i < size - 1; i++)
			{
				array[i] = array[i + 1];
			}
			size--;
			return ele;
		}
		else
			return -1;
	}
	
	int size()
	{
		return size;
	}
	
	int getCapacity()
	{
		return capacity;
	}
	
	void print()
	{
		for(int i = 0; i < size; i++)
			cout<<array[i]<<" ";
		cout<<endl;
	}
}
