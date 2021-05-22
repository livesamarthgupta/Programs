#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n];
	int res = 0;
	for(int i = 0; i < n; i++) {
		cin>>arr[i];
		res = res ^ arr[i]; //get xor of two unique numbers
	}
	
	// get the position of set bit in xor value
	int temp = res;
	int pos = 0;
	while(temp & 1 == 0) {
		pos++;
		temp = temp >> 1;
	}
	
	//answers
	int n1 = 0;
	int n2 = 0;
	
	//xor all no. whose bit is set at pos to get n1
	int mask = 1 << pos;
	for(int i = 0; i < n; i++) {
		if(mask & arr[i])
			n1 = n1 ^ arr[i];
	}
	
	//find n2
	n2 = res ^ n1;
	
	cout<<min(n1, n2)<<" "<<max(n1, n2)<<endl;
	
	
	return 0;
}
