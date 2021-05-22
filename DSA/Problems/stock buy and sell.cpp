#include<bits/stdc++.h>
using namespace std;

void localMinima(vector<int> &min, int arr[], int n)
{
	if(arr[0] < arr[1])
		min.push_back(0);
	for(int i = 1; i < n - 1; i++)
	{
		if(arr[i] < arr[i + 1] && arr[i] < arr[i - 1])
			min.push_back(i);
	}
}

void localMaxima(vector<int> &max, int arr[], int n)
{
	for(int i = 1; i < n - 1; i++)
	{
		if(arr[i] > arr[i - 1] && arr[i + 1] < arr[i])
			max.push_back(i);
	}
	if(arr[n - 1] > arr[n - 2])
		max.push_back(n - 1);
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin>>arr[i];
	vector<int> min;
	vector<int> max;
	localMinima(min, arr, n);
	localMaxima(max, arr, n);
	for(int i = 0, j = 0; i < min.size() && j < max.size(); i++, j++)
	{
		cout<<"(";
		cout<<min[i]<<" ";
		cout<<max[j]<<")";
	}
}
