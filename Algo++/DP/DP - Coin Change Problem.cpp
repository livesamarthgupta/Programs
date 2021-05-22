#include <bits/stdc++.h>
using namespace std;

int min_coins(int amount, int coins[], int T, int dp[]) {
    if(amount == 0)
        return 0;

    //check dp array
    if(dp[amount] != 0)
        return dp[amount];

    //else
    int ans = INT_MAX;
    for(int i = 0; i < T; i++) {
        if(amount - coins[i] >= 0) {
            int subprob = min_coins(amount - coins[i], coins, T, dp);
            ans = min(ans, subprob + 1);
        }
    }
    dp[amount] = ans;
    return dp[amount];
}


int min_coins_bottom_up(int amount, int coins[], int T) {
    int dp[100] = {0};
    //fill dp array bottom up 1....amount
    for(int n = 1; n <= amount; n++) {
        dp[n] = INT_MAX;
        for(int i = 0; i < T; i++) {
            if(n - coins[i] >= 0) {
                int subprob = dp[n - coins[i]];
                dp[n] = min(dp[n], subprob + 1);
            }
        }
    }
    return dp[amount];
}

int main() {
    int amount;
    cin>>amount;
    int T;
    cin>>T;
    int arr[T];
    for(int i = 0; i < T; i++)
        cin>>arr[i];

    int dp[100] = {0};

    // cout<<min_coins(amount, arr, T, dp);
    cout<<min_coins_bottom_up(amount, arr, T);
}
