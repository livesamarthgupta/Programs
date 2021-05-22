#include<iostream>

using namespace std;

int main(){
	int arr[1000], n, ele, min, max, guess;
	bool found = false;
	cout<<"Enter size of list:";
	cin>>n;
	cout<<"Enter sorted elements in list:";
	for(int i = 0; i < n; i++)
		cin>>arr[i];
	cout<<"Enter element to search:";
	cin>>ele;
	min = 0;
	max = n-1;
	while(min <= max)
	{
		guess = (min + max)/2;
		if(arr[guess] == ele)
		{
			cout<<"Element found at position:"<<guess+1;
			found = true;
			break;
		}
		else if(arr[guess] > ele)
			max = guess - 1;
		else if(arr[guess] < ele)
			min = guess + 1;
	}
	if(found == false)
		cout<<"Element not found in list";
	return 0;
	//Big-O(logn), Big-Theta(logn), Big-Omega(1)
}

