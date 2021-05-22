#include<bits/stdc++.h>
using namespace std;


int find_lower_bound(int arr[], int n, int key) {
	int s = 0; 
	int e = n - 1;
	int ans  = -1;
	
	while(s <= e) {
		int mid = (s + e) / 2;
		if(arr[mid] == key) {
			ans = mid;
			e = e - 1;
		} else if(arr[mid] < key)
			s = mid + 1;
		else 
			e = mid - 1;
	}
	
	return ans;
}

int find_upper_bound(int arr[], int n, int key) {
	int s = 0;
	int e = n - 1;
	int ans = -1;
	
	while(s <= e) {
		int mid = (s + e) / 2;
		if(arr[mid] == key) {
			ans = mid;
			s = mid + 1;
		} else if(arr[mid] < key) 
			s = mid + 1;
		else 
			e = mid - 1;
	}
	
	return ans;
}

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin>>arr[i];
		
	int q;
	cin>>q;
	while(q--) {
		int key;
		cin>>key;
		cout<<find_lower_bound(arr, n, key)<<" ";
		cout<<find_upper_bound(arr, n, key)<<endl;
	}
	
	
	
	return 0;
}
