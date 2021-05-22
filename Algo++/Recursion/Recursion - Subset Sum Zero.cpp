#include <iostream>
using namespace std;

bool check_sum_is_zero(int arr[], int n, int sum, int i, bool included) {
    if(i == n) {
       return sum == 0 && included;
    }

    bool inc = check_sum_is_zero(arr, n, sum + arr[i], i + 1, true);
    bool exc = check_sum_is_zero(arr, n, sum, i + 1, included);

    return inc || exc;

}



int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        int out[n];
        bool check = check_sum_is_zero(arr, n, 0, 0, false);
        if(check) {
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }

    }
}
