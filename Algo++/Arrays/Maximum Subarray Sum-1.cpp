#include<bits/stdc++.h>
using namespace std;

// Maximum subarray sum

int main() {
	
	int arr[] = {-1, -2, 3, 4, 5, -2, 6, -9, -10};
	int n = sizeof(arr)/sizeof(int);
	int prefixSum[n] = {0};
	prefixSum[0] = arr[0];
	for(int i = 1; i < n; i++) {
		prefixSum[i] = prefixSum[i - 1] + arr[i];
	}
	
	int csum = 0;
	int msum = 0;
	int left = -1;
	int right = -1;
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			csum = prefixSum[j] - prefixSum[i - 1];
			if(csum > msum)
			{
				msum = csum;
				left = i; 
				right = j;
			}
		}
	}
	
	cout<<msum<<endl;
	return 0;
}
