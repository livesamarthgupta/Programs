#include <bits/stdc++.h>
using namespace std;

int rod_cut(int arr[], int n, int dp[]) {
    if(n <= 0)
        return 0;

    if(dp[n] != 0)
        return dp[n];

    int ans = INT_MIN;
    for(int i = 0; i < n; i++) {
        int cut = i + 1;
        int current = rod_cut(arr, n - cut, dp);
        ans = max(ans, current);
    }
    return dp[n] = ans;
}

int rod_cut_bottom_up(int arr[], int n) {
    int dp[100] = {0};
    dp[0] = 0;

    for(int len = 1; len <= n; len++) {
        int ans = INT_MIN;
        for(int i = 0; i < len; i++) {
            int cut = i + 1;
            int current = arr[i] + dp[len - cut];
            ans = max(ans, current);
        }
        dp[len] = ans;
    }
    return dp[n];
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];

    int dp[100] = {0};
    cout<<rod_cut_bottom_up(arr, n);
}
