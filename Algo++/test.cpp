#include<bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin>>arr[i];
		
	int key;
	cin>>key;
	sort(arr, arr+n);
	
	int left = 0, right = n - 1;
	while(left < right) {
		if(arr[left] + arr[right] == key)
		cout<<arr[left++]<<" and "<<arr[right--]<<endl;
		else if(arr[left] + arr[right] > key)
			right--;
		else if(arr[left] + arr[right] < key)
			left++;
	}
	
	return 0;
}
