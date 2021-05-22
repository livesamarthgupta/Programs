#include<bits/stdc++.h>
using namespace std;

int countSetBits(int n) {
	int ans = 0;
	while(n > 0) {
		n = n & n - 1;
		ans++;
	}
	
	return ans;
}

int countSetBitsInRange(int a, int b) {
	int ans = 0;
	for(int i = a; i <= b; i++) {
		ans += countSetBits(i);
	}
	return ans;
}

int main() {
	int q;
	cin>>q;
	while(q--) {
		int a, b;
		cin>>a>>b;
		cout<<countSetBitsInRange(a, b)<<endl;
	}
	return 0;
}
