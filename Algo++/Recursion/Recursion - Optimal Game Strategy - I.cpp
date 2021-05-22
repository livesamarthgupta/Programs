#include <iostream>
using namespace std;

int get_maximum(int*arr, int n, int s, int e) {
    if(s > e) {
        return 0;
    }

    int first = arr[s] + min(get_maximum(arr, n, s + 2, e), get_maximum(arr, n, s + 1, e - 1));

    int last = arr[e] + min(get_maximum(arr, n, s, e - 2), get_maximum(arr, n, s + 1, e - 1));

    return max(first, last);

}



int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];

    int maximum = get_maximum(arr, n, 0, n - 1);
    cout<<maximum<<endl;
}
