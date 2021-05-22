#include <bits/stdc++.h>
using namespace std;

long long fast_expo(int a, int b, int c) {
    long long ans = 1;
    a = a % c;
    if(a == 0) return 0;
    if(b == 1) return a;
    while(b > 0) {
        int last_dig = (b & 1);
        if(last_dig) {
            ans = (ans * a) % c;
        }
        a = (a * a) % c;
        b = b >> 1;
    }
    return ans;
}

int main() {
    int a, b, c;
    cin>>a>>b>>c;
    cout<<fast_expo(a, b, c)<<endl;
}
