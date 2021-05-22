#include <iostream>
using namespace std;

long long prefix[100005];
long long arr[100005];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        memset(prefix, 0, sizeof(prefix));
        prefix[0] = 1;
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            cin>>arr[i];
            sum += arr[i];
            sum %= n;
            sum = (sum + n) % n;
            prefix[sum]++;
        }

        long long ans = 0;
        for(int i = 0; i < n; i++) {
            long long m = prefix[i];
            ans += m * (m - 1) / 2;
        }

        cout<<ans<<endl;

    }
}
