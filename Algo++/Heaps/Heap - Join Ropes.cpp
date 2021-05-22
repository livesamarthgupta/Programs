#include <bits/stdc++.h>
using namespace std;

int join_ropes(int*arr, int n) {
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr + n);

    int cost = 0;
    while(pq.size() > 1) {
        int A = pq.top();
        pq.pop();

        int B = pq.top();
        pq.pop();

        int newrope = A + B;
        cost += newrope;
        pq.push(newrope);
    }
    return cost;
}

int main() {
    int arr[] = {4,3,2,6};
    int n = 4;
    int cost = join_ropes(arr, n);
    cout<<cost<<endl;
}
