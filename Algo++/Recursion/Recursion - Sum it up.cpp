#include <bits/stdc++.h>
using namespace std;


void find_combinations(int *arr, int n, int i, int key, vector<int> &v, set<vector<int>> &s) {
    //base case
    if(i == n) {
        return;
    }

    if(i < n) {
        int sum = 0;
        for(auto ele : v)
            sum += ele;
        if(sum == key) {
            s.insert(v);
        }
    }
    
    //recursive case

    //either we include ith element
    v.push_back(arr[i]);
    find_combinations(arr, n, i + 1, key, v, s);

    //this method is known as backtracking when we come back to parent function call and reset changes.
    v.pop_back();


    //either we don't include ith element
    find_combinations(arr, n, i + 1, key, v, s);


}


int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    sort(arr, arr + n);
    int key;
    cin>>key;

    vector<int> v;
    set<vector<int>> s;

    find_combinations(arr, n, 0, key, v, s);    

    for(auto vec : s) {
        for(auto ele : vec)
            cout<<ele<<" ";
            cout<<endl;
    }
}
