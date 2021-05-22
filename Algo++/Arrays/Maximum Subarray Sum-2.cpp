#include<bits/stdc++.h>
using namespace std;

// Maximum subarray sum (Kadane's Algo)

int main() {
	
	int arr[] = {-1, -2, 3, 4, 5, -2, 6, -9, -10};
	int n = sizeof(arr)/sizeof(int);
	
	int csum = 0;
	int msum = 0;
	for(int i = 0; i < n; i++) {
		csum += arr[i];
		if(csum < 0)
			csum = 0;
		msum = max(csum, msum);
	}
	
	cout<<msum<<endl;
	
	
	return 0;
}
