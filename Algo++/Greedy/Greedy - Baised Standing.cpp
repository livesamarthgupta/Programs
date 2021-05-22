#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    int a[10000];
    while(t--) {
        memset(arr, 0, sizeof arr);
        int n;
        cin>>n;
        string name;
        int rank;
        for(int i = 0; i < n; i++) {
            cin>>name>>rank;
            a[rank]++;
        }

        int sum = 0;
        int actual_rank = 1;
        for(int i = 1; i <= n; i++) {
            while(a[i]) {
                sum += abs(actual_rank, i);
                a[i]--;
                actual_rank++;
            }
        }
        cout<<sum<<endl;

    }
}
