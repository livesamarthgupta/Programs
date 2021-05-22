#include<bits/stdc++.h>
using namespace std;

// Pair sum (two pointer)(sorted)

int main() {
	
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int n = sizeof(arr)/sizeof(int);
	
	int i = 0; 
	int j = n - 1;
	int sum = 10;
	while(i < j) {
		int csum = arr[i] + arr[j];
		if(csum == sum) {
			cout<<arr[i]<<" and "<<arr[j]<<endl;
			i++;
			j--;
		}
		else if(csum < sum) {
			i++;
		}
		else if(csum > sum) {
			j--;
		}
	}
	
	
	return 0;
}
