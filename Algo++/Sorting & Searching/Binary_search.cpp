#include<bits/stdc++.h>
using namespace std;

//binary search

int binary_search(int a[], int n, int key) {
	int s = 0; 
	int e = n - 1;
	while(s <= e) {
		int m = (s + e) / 2;
		if(a[m] == key) {
			return m;
		} else if(a[m] < key) {
			s = m + 1;
		} else { 
			e = m - 1;
		}
	}
	return -1;
}

int main() {
	
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++) {
		cin>>arr[i];
	}
	
	int key;
	cin>>key;
	
	cout<<binary_search(arr, n, key)<<endl;
	
	return 0;
}
