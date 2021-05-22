#include <bits/stdc++.h>
using namespace std;

int profit(int wines[], int y, int i, int j, int dp[][100]) {
    if(i > j)
        return 0;

    //check dp array
    if(dp[i][j] != 0)
        return dp[i][j];

    //recursive case
    int op1 = wines[i] * y + profit(wines, y + 1, i + 1, j, dp);
    int op2 = wines[j] * y + profit(wines, y + 1, i, j - 1, dp);
    dp[i][j] = max(op1, op2);
    return dp[i][j];
}


int main() {
    int n;
    cin>>n;
    int wines[n];
    for(int i = 0; i < n; i++)
        cin>>wines[i];

    int dp[100][100] = {0};
    cout<<profit(wines, 1, 0, n - 1, dp);
}
