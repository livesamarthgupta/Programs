#include<bits/stdc++.h>
using namespace std;

//binary search on sorted and rotated array

int find_key(int arr[], int n, int key) {
	int s = 0;
	int e = n - 1;
	
	while(s <= e) {
		int mid = (s + e) / 2; 
		if(arr[mid] == key)
			return mid;
		else if(arr[s] < arr[mid]) {
			if(key >= arr[s] && key <= arr[mid])
				e = mid - 1;
			else 
				s = mid + 1;
		} else {
			if(key <= arr[e] && key >= arr[mid])
				s = mid + 1;
			else 
				e = mid - 1;
		}
	}
}

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++)	
		cin>>arr[i];
		
	int key;
	cin>>key;
	
	cout<<find_key(arr, n, key);
	
	
	return 0;
}
