#include<iostream>

using namespace std;

int main(){
	int arr[1000], n, ele;
	bool found = false;
	cout<<"Enter size of List: ";
	cin>>n;
	cout<<"Enter elements in list: ";
	for(int i = 0; i < n; i++)
		cin>>arr[i];
	cout<<"Enter element to search: ";
	cin>>ele;
	for(int i = 0; i < n; i++)
	{
		if(arr[i] == ele)
		{
			cout<<"Element found at position:"<<(i+1);
			found = true;
			break;
		}
	}
	if(found == false)
		cout<<"Element not present in list ";
	return 0;
	//Big-O(n), Big-theta(n), Big-omega(1)
}

