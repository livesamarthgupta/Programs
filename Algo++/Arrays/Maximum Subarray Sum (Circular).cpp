#include<bits/stdc++.h>
using namespace std;


int main() {
	
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int arr[n];
		for(int i = 0; i < n; i++)
			cin>>arr[i];
			
		int cMaxSum = 0;
		int cMinSum = 0;
		
		int maxSum = INT_MIN;
		int minSum = INT_MAX;
		
		int total = 0;
		
		for(int i = 0; i < n; i++) {
			
			total += arr[i];
			
			cMaxSum += arr[i];
			cMinSum += arr[i];
			
			if(cMaxSum < 0) cMaxSum = 0;
			if(cMinSum > 0) cMinSum = 0;
			
			maxSum = max(maxSum, cMaxSum);
			minSum = min(minSum, cMinSum);
		}
		if(maxSum > 0) 
			cout<<max(maxSum, total-minSum)<<endl;
		else 
			cout<<maxSum<<endl;
		
	}
	
	return 0;
}
