#include<bits/stdc++.h>
using namespace std;


int find_item(int arr[], int n, int key) {
	int s = 0;
	int e = n - 1;
	
	while(s <= e) {
		int mid = (s + e) / 2;
		if(arr[mid] == key)
			return mid;
		else if(arr[s] < arr[mid]) {
			//left array is sorted
			if(key >= arr[s] && key <= arr[mid])
				e = mid - 1;
			else 
				s = mid + 1;
		} else {
			//right array is sorted
			if(key <= arr[e] && key >= arr[mid])
				s = mid + 1;
			else 
				e = mid - 1;
		}
	}
	return -1;
}

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin>>arr[i];
	
	int key;
	cin>>key;
	
	cout<<find_item(arr, n, key)<<endl;
	
	return 0;
}
