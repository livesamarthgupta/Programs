#include <bits/stdc++.h>
using namespace std;


vector<int> primeSieve(int *isPrime) {
    //special case 
    isPrime[2] = 1;

    //odd numbers
    for(long long i = 3; i < 611954; i+=2) {
        isPrime[i] = 1;
    }

    for(long long i = 3; i < 611954; i++){
        if(isPrime[i] == 1) {
            for(long long j = i * i; j < 611954; j+=i) {
                isPrime[j] = 0;
            }
        }
    }

    vector<int> primes;
    for(long long i = 0; i < 611954; i++) {
        if(isPrime[i] == 1)
            primes.push_back(i);
    }

    return primes;
}

int main() {
    int isPrime[611954] = {0};
    long long n;
    cin>>n;
    vector<int> primes;
    primes = primeSieve(isPrime);
    cout<<primes[n - 1]<<endl;

}
