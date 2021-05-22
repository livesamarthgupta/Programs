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
	
	int n;
	cin>>n;
	
	int i = 0;
	int p = primes[0];
	int ans = 1;
	
	while(p * p <= n) {
		if(n % p == 0) {
			//store power of each factor
			int cnt = 0;
			while(n % p == 0) {
				cnt++;
				n = n / p;
			}
			ans = ans * (cnt + 1);
		}
			
		p = primes[i];
		i++;
	}
	
	if(n != 1)
		ans = ans * 2;
		
	cout<<ans<<endl;
	
	return 0;
}
