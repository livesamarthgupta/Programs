#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b , a % b);
}

int main() {
    long long a, b;
    cin>>a>>b;
    long long lcm = (a * b) / gcd(a, b);
    cout<<lcm<<endl;
}
