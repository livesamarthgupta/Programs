#include <bits/stdc++.h>
using namespace std;

int longestSubarrayKSum(int*arr, int n, int k) {
    int pre = 0;
    unordered_map<int, int> map;
    int len = 0;
    for(int i = 0; i < n; i++) {
        pre += arr[i];
        if(pre == k) {
            len = max(len, i + 1);
        } 

        if(map.find(pre - k) != map.end()) {
            len = max(len, i - map[pre - k]);
        } else {
            map[pre] = i;
        }
    }
    return len;
}

int main() {
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];

    cout<<longestSubarrayKSum(arr, n, k);
}
