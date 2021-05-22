#include<bits/stdc++.h>
using namespace std;

bool isOdd(int n) {
	return (n & 1);
}

int getBit(int n, int i) {
	int mask = (1 << i);
	int bit = ((n & mask) > 0) ? 1 : 0;
	return bit;
}

void setBit(int &n, int i) {
	int mask = (1 << i);
	n = n | mask;
}

void clearBit(int &n, int i){
	int mask = ~(1 << i);
	n = n & mask;
}

void updateBit(int &n, int i, int v) {
	int mask = ~(1 << i);
	int cleared_n = n & mask;
	n = cleared_n & (v << i);
}

void clearLastIBits(int &n, int i) {
	int mask = (~0) << i;
	n = n & mask;
}

void clearRangeItoJ(int &n, int i, int j) {
	int left_part = (~0) << (j + 1);
	int right_part = (1 << i) - 1;
	int mask = left_part | right_part;
	n = n & mask;
}

int main() {
	
	
	
	return 0;
}
