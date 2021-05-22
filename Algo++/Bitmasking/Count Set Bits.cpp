#include<bits/stdc++.h>
using namespace std;


// O(logN + 1)
int countBits(int n) {
	
	int ans = 0;
	while(n > 0) {
		ans = ans + (n & 1);
		n = n >> 1;
	}
	
	return ans;
}

//O(no. of set bits)
int countBitsFast(int n) {
	/* unset i set bits from right 
		for(int count = 0; count < i; count++)
			n = n & (n - 1);
	*/
	
	int ans = 0;
	while(n > 0) {
		n = n & (n - 1);
		ans++;
	}
	return ans;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		cout<<__builtin_popcount(n)<<endl;
	}	
	
	return 0;
}
