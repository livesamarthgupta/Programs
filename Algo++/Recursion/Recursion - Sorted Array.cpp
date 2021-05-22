#include <iostream>
using namespace std;

bool isSorted(int *arr, int n) {
    if(n == 0)
        return true;
    
    if(arr[n] < arr[n - 1])
        return false;
    else return isSorted(arr, n - 1);
}


int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];

    if(isSorted(arr, n) == 1)
        cout<<"true"<<endl;
    else 
        cout<<"false"<<endl;
}
