#include<bits/stdc++.h>
using namespace std;


void primeSieve(int *isPrime) {
	
	//special cases
	isPrime[2] = 1;
	
	//mark all odd as possible
	for(long long i = 3; i <= 1000000; i += 2)
		isPrime[i] = 1;
		
	for(long long i = 3; i <= 1000000; i += 2) {
		if(isPrime[i] == 1) {
			for(long long j = i * i; j <= 1000000; j += i)
				isPrime[j] = 0;
		}
	}
}

int main() {
	int isPrime[1000005] = {0};
	primeSieve(isPrime);
	int prefixArray[1000005] = {0};
	for(long long i = 1; i <= 1000000; i++)
		prefixArray[i] = prefixArray[i - 1] + isPrime[i];
		
	int n;
	cin>>n;
	while(n--) {
		int a, b;
		cin>>a>>b;
		cout<<prefixArray[b] - prefixArray[a - 1]<<endl;
	}
	
}
