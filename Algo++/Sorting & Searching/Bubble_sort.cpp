#include<bits/stdc++.h>
using namespace std;

//Bubble Sort

void Bubble_sort(int a[], int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n - i - 1; j++) {
			if(a[j] > a[j + 1])
			swap(a[j], a[j + 1]);
		}
	}
}

int main() {
	
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++) {
		cin>>arr[i];
	}
	
	Bubble_sort(arr, n);
	
	for(auto i : arr)
		cout<<i<<" ";
		cout<<endl;
	
	return 0;
}
