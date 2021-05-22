#include <iostream>
using namespace std;


int findM(int *arr, int n, int m) {

    if(n == -1)
        return -1;
    if(arr[n] == m)
        return n;
    else return findM(arr, n - 1, m);
}


int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    int m;
    cin>>m;
    cout<<findM(arr, n, m)<<endl;    
}
