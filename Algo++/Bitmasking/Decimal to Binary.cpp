#include<bits/stdc++.h>
using namespace std;

int decimalToBinary(int n) {
	int ans = 0;
	int pow = 1;
	
	while(n > 0) {
		int last_bit = (n & 1);
		n = n >> 1;
		ans += pow * last_bit;
		pow *= 10;
	}
	
	return ans;
}

int main() {
	int n;
	cin>>n;
	cout<<decimalToBinary(n)<<endl;	
	return 0;
}
