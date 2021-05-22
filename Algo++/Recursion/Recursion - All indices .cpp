#include <bits/stdc++.h>
using namespace std;

int get_index(int *a, int n, int *out, int i, int m) {
    if(n == -1)
        return i;

    if(a[n] == m) {
        out[i] = n;
        return get_index(a, n - 1, out, i + 1, m);
    } else {
        return get_index(a, n - 1, out, i, m);
    }
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    
    int m;
    cin>>m;

    int out[n];
    int i = get_index(arr, n, out, 0, m);
    reverse(out, out + i);
    for(int j = 0; j < i; j++)
        cout<<out[j]<<" ";
        cout<<endl;
}
