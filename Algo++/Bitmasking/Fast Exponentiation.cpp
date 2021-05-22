#include<bits/stdc++.h>
using namespace std;

int fast_exponentiation(int n, int i) {
	int ans = 1;
	while(i > 0) {
		int last_bit = i & 1;
		i = i >> 1;
		if(last_bit) {
			ans = ans * n;
		}
		n = n * n;
	}
	
	return ans;
}

int main() {
	int n, i;
	cin>>n>>i;
	
	cout<<fast_exponentiation(n, i)<<endl;
	return 0;
}
