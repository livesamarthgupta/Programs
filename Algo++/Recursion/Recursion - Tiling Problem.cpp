#include <bits/stdc++.h>
using namespace std;

int values[100000];

int find_ways_to_place(int n, int m) {
    if(n <= m - 1) {
        return 1;
    }

    int ans = 0;

    if(values[n - 1] == -1)
        values[n - 1] =  find_ways_to_place(n - 1, m);
     
    ans += values[n - 1];

    if(values[n - m] == -1)
        values[n - m] = find_ways_to_place(n - m, m);
     
    ans += values[n - m];

    return ans;
}


int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, m;
        cin>>n>>m;
        memset(values, -1, sizeof(values));
        cout<<find_ways_to_place(n, m)<<endl;
    }
}
