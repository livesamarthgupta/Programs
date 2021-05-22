#include<bits/stdc++.h>
using namespace std;

// replace bits in N by M

int clearBitsItoJ(int n, int i, int j) {
	int left_part = (~0) << (j + 1);
	int right_part = (1 << i) - 1;
	int mask = left_part | right_part;
	return n & mask;
}


int replace_bits(int n, int m, int i, int j) {
	int cleared_n = clearBitsItoJ(n, i, j);
	m = m << i;
	return cleared_n | m;
}


int main() {
	int n, m, i, j;
	cin>>n>>m>>i>>j;
	
	cout<<replace_bits(n, m, i, j)<<endl;
	
	return 0;
}
