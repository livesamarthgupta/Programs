#include<bits/stdc++.h>
using namespace std;

int main() {
	int x[64] = {0};
	
	int n;
	cin>>n;
	for(int i = 0; i < n; i++) {
		int no;
		cin>>no;
		
		//count bits and store in array
		int j = 0;
		while(no > 0) {
			int last_bit = no & 1;
			no = no >> 1;
			x[j] += last_bit;
			j++;
		}
	}
	
	
	int ans = 0;
	int p = 1;
	for(int i = 0; i < 64; i++) {
		int mod = x[i] % 3; // % n when n numbers are repeating
		ans = ans + p * mod;
		p = p << 1;
	}
	
	cout<<ans<<endl;
	
}
