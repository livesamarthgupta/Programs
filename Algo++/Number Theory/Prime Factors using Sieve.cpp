#include<bits/stdc++.h>
using namespace std;

void primeSieve(int *isPrime) {
	
	isPrime[2] = 1;
	
	for(int i = 3; i < 1000; i+=2) 
		isPrime[i] = 1;
		
	for(int i = 3; i < 1000; i+=2) {
		if(isPrime[i] == 1) {
			for(int j = i * i; j < 1000; j += i)
				isPrime[j] = 0;
		}
	}
}

int main() {
	int isPrime[1000] = {0};
	primeSieve(isPrime);
	vector<int> primes;
	//get all primes in vector
	for(int i = 0; i < 1000; i++)
		if(isPrime[i] == 1)
			primes.push_back(i);
	
	vector<int> factors;
	int n;
	cin>>n;
	
	int i = 0;
	int p = primes[0];
	
	while(p * p <= n) {
		if(n % p == 0)
			factors.push_back(p);
			while(n % p == 0)
				n = n / p;
		p = primes[i];
		i++;
	}
	
	if(n != 1)
		factors.push_back(n);
		
	for(auto i : factors)
		cout<<i<<" ";
		cout<<endl;
	
	return 0;
}
