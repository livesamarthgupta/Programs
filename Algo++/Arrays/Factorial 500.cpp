#include<bits/stdc++.h>
using namespace std;
#define MAX 1500

int multiply(int x, int result[], int size) {
	int carry = 0;
	
	for(int i = 0; i < size; i++) {
		int prod = (result[i] * x) + carry;
		result[i] = prod % 10;
		carry = prod / 10;
	}
	
	while(carry) {
		result[size] = carry % 10;
		carry /= 10;
		size++;
	}
	
	return size;
}



void factorial(int n) {
	int result[MAX];
	
	result[0] = 1;
	int size = 1;
	for(int i = 2; i <= n; i++)
		size = multiply(i, result, size);
	
	for(int i = size - 1; i >= 0; i--)
		cout<<result[i];
		cout<<endl;
}





int main() {
	int n;
	cin>>n;
	
	factorial(n);

	return 0;
}
