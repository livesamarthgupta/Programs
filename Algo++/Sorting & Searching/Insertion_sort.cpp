#include<bits/stdc++.h>
using namespace std;

// Insertion Sort

void Insertion_sort(int a[], int n) {
	for(int i = 1; i < n; i++) {
		int temp = a[i];
		int j = i - 1;
		while(j >= 0 && a[j] > temp) {
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = temp;
	}
}

int main() {
	
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin>>arr[i];
		
	Insertion_sort(arr, n);
	
	for(auto i : arr)
		cout<<i<<" ";
		cout<<endl;
	
	return 0;
}
