#include<bits/stdc++.h>
using namespace std;

int main()  {
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin>>arr[i];
	int key;
	cin>>key;
		
	sort(arr, arr+n);
	for(int i = 0; i < n; i++) {
		int l = i + 1;
		int r = n - 1;
		while(l < r) {
			if(arr[i] + arr[l] + arr[r] == key)
			{
				cout<<arr[i]<<", "<<arr[l]<<" and "<<arr[r]<<endl;
				l++;
				r--;
			} else if(arr[i] + arr[l] + arr[r] < key)
				l++;
			else if(arr[i] + arr[l] + arr[r] > key)
				r--;
		}
	}
	
	
	
	
	
	
	return 0;
}
