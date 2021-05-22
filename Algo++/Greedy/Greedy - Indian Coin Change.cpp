#include <bits/stdc++.h>
using namespace std;

int get_coins_count(int*coins, int n, int money) {
    int ans = 0;
    while(money > 0){
        int idx = upper_bound(coins, coins + n, money) - 1 - coins;
        money -= coins[idx];
        ans++;
    }
    return ans;
}


int main() {
    int money;
    cin>>money;
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int n = sizeof(coins) / sizeof(int);
    cout<<get_coins_count(coins, n, money);
}
