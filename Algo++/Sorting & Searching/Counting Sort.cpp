#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n];
	int freq[10000] = {0};
	int maximum = -1;
	for(int i = 0; i < n; i++)	{
		cin>>arr[i];
		freq[arr[i]]++;
		maximum = max(maximum, arr[i]);
	}
	
	for(int i = 0; i <= maximum; i++) {
		if(freq[i] > 0)
		for(int j = 0; j < freq[i]; j++)
			cout<<i<<" ";
	}
	
		
		
	
	
	
	return 0;
}
