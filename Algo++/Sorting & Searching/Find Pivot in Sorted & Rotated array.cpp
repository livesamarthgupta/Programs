#include<bits/stdc++.h>
using namespace std;


int find_pivot(int arr[], int n) {
	int s = 0;
	int e = n - 1;
	
	while(s <= e) {
		int mid = (s + e) / 2;
		if(arr[mid] > arr[mid + 1])
			return mid;
		else if(arr[s] <= arr[mid]) {
			//left array is sorted
				s = mid + 1;
		} else {
			//right array is sorted 
				e = mid - 1;
		}
	}
	return n - 1;
}

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin>>arr[i];
	
	
	cout<<find_pivot(arr, n)<<endl;
	
	return 0;
}
