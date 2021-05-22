#include <bits/stdc++.h>
using namespace std;

int longestConsecutiveSubsequence(int*arr, int n) {
    unordered_map<int, int> map;

    for(int i = 0; i < n; i++) {
        int no = arr[i];

        //case 1: when new streak is formed
        if(!map.count(no - 1) && !map.count(no + 1)) {
            map[no] = 1;
        } 
        //case 2: when two streaks are joined
        else if(map.count(no - 1) && map.count(no + 1)) {
            int lenLeft = map[no - 1];
            int lenRight = map[no + 1];
            int len = lenLeft + 1 + lenRight;
            map[no - lenLeft] = len;
            map[no + lenRight] = len;
        }
        //case 3: when element is added at streak end
        else if(map.count(no - 1) && !map.count(no + 1)) {
            int len = map[no - 1];
            map[no - len] = len + 1;
            map[no] = len + 1;
        }
        //case 4: when element is added at streak front
        else {
            int len = map[no + 1];
            map[no + len] = len + 1;
            map[no] = len;
        }
    }

    int streak = 0;
    for(auto p : map) {
        streak = max(streak, p.second);
    }

    return streak;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];

    cout<<longestConsecutiveSubsequence(arr, n);
}
