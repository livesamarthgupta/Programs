#include<bits/stdc++.h>
using namespace std;

//Selection sort

void Selection_sort(int a[], int n) {
	for(int i = 0; i < n; i++) {
		int min = i;
		for(int j = i; j < n; j++) {
			if(a[j] < a[min])
				min = j;
		}
		swap(a[i], a[min]);
	}
}

int main() {
	
	int n;
	cin>>n;
	int arr[n] ={0};
	for(int i = 0; i < n; i++) {
		cin>>arr[i];
	}
	
	Selection_sort(arr, n);
	
	for(auto i : arr)
		cout<<i<<",";
		cout<<endl;
	
	return 0;
}
