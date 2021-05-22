#include<bits/stdc++.h>
using namespace std;

void primeSieve(int isPrime[], int n) {
	
	//special case
	isPrime[0] = isPrime[1] = 0;
	isPrime[2] = 1;
	
	//mark all odd number as true
	for(int i = 3; i <= n; i+=2) {
		isPrime[i] = 1;
	}
	
	for(int i = 3; i <= n; i+=2) {
		if(isPrime[i] == 1) {
			for(int j = i * i; j <= n; j+=i)
				isPrime[j] = 0;
		}
	}
}

int main() {
	int n;
	cin>>n;
	int isPrime[n + 1] = {0};
	primeSieve(isPrime, n);
	for(int i = 0; i <= n; i++) {
		if(isPrime[i] == 1)
			cout<<i<<" ";
	}
	
	return 0;
}
