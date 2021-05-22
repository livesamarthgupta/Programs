#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin>>arr[i];
	
	int water = 0;
	int left_max = 0, right_max = 0;
	int lo = 0, hi = n - 1;
	
	while(lo <= hi) {
		if(arr[lo] < arr[hi]) {
			if(arr[lo] > left_max)
				left_max = arr[lo];
			else 
				water += left_max - arr[lo];
			lo++;
		} else {
			if(arr[hi] > right_max) 
				right_max = arr[hi];
			else 
				water += right_max - arr[hi];
			hi--;
		}
	}
	
	cout<<water<<endl;
	
	
	return 0;
}
