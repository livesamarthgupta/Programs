#include <iostream>
using namespace std;

int max_sum(int arr[], int n) {
    int dp[100] = {0};
    dp[0] = a[0] > 0 ? a[0] : 0;
    int max_so_far = dp[0];

    for(int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + arr[i];
        if(dp[i] < 0) {
            dp[i] = 0;
        }
        max_so_far = max(max_so_far, dp[i]);
    }
    return max_so_far;
}

//kadane's algorithms
int max_sum_kadane(int arr[], int n) {
    //handle special case when all elements are negative in array
    
    int current_sum = 0;
    int max_sum = 0;
    for(int i = 0; i < n; i++) {
        current_sum += arr[i];
        if(current_sum < 0) {
            current_sum = 0;
        }
        max_sum = max(max_sum, current_sum);
    }
    return max_sum;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];

    cout<<max_sum(arr, n);
}
