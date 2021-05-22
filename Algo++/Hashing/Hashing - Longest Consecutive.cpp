#include <bits/stdc++.h>
using namespace std;

int longestConsecutiveSubsequence(int*arr, int n) {
    unordered_set<int> set;

    for(int i = 0; i < n; i++) 
        set.insert(arr[i]);

    int max_streak = 1;
    for(int i = 0; i < n; i++) {
        int no = arr[i];
        //check if no can be head of a streak i.e no - 1 doesn't exist in set
        if(set.find(no - 1) == set.end()) {
            int streak = 1;
            int next_no = no + 1;
            //count consecutive elements after no
            while(set.find(next_no) != set.end()) {
                streak++;
                next_no += 1;
            }
            max_streak = max(max_streak, streak);
        }
    }
    return max_streak;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];

    cout<<longestConsecutiveSubsequence(arr, n);
}
