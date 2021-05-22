#include<iostream>

using namespace std;

int main(){
	int n, arr[100];
	cout<<"Enter size of list:";
	cin>>n;
	cout<<"Enter elements in list:";
	for(int i = 0; i < n; i++)
		cin>>arr[i];
	for(int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while(j >= 0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
	for(int i = 0; i < n; i++)
		cout<<arr[i]<<" ";
	return 0;
	/*
	worst case: O(n^n)
	average case: O(n^n)
	best case: O(n)
	*/
}

