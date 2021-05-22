#include <bits/stdc++.h>
using namespace std;

int min_steps(int n, int dp[]) {
    if(n == 1)
        return 0;
    
    //check dp array 
    if(dp[n] != 0)
        return dp[n];

    int op1, op2, op3;
    op1 = op2 = op3 = INT_MAX;

    if(n % 3 == 0) {
        op1 = min_steps(n/3, dp) + 1;
    }
    if(n % 2 == 0) {
        op2 = min_steps(n/2, dp) + 1;
    }
    op3 = min_steps(n - 1, dp) + 1;

    int ans = min(min(op1, op2), op3);
    return dp[n] = ans;
}

int min_steps_top_down(int n) {
    int dp[100] = {0};
    for(int i = 2; i <= n; i++) {
        int op1, op2, op3;
        op1 = op2 = op3 = INT_MAX;
        if(i % 3 == 0)
            op1 = dp[i / 3] + 1;
        if(i % 2 == 0)
            op2 = dp[i / 2] + 1;
        op3 = dp[i - 1]  + 1;
        dp[i] = min(min(op1, op2), op3);
    }
    return dp[n];
}


int main() {
    int n;
    cin>>n;
    int dp[100] = {0};
    cout<<min_steps_top_down(n);
}
