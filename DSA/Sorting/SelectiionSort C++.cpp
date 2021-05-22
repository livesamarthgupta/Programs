#include<iostream>

using namespace std;

int main(){
	int arr[1000], n;
	cout<<"Enter number of elements in list: ";
	cin>>n;
	cout<<"Enter elements in list: ";
	for(int i = 0; i < n; i++)
		cin>>arr[i];
	for(int i = 0; i < n-1; i++)
	{
		int min = arr[i];
		int minIndex = i;
		for(int j = i+1; j < n; j++)
		{
			if(arr[j] < min)
			{
				min = arr[j];
				minIndex = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
	cout<<"Sorted List:"<<endl;
	for(int i = 0; i < n; i++)
		cout<<arr[i]<<endl;

	return 0;
	//Big-O-Omega-Theta(n^n)
}

