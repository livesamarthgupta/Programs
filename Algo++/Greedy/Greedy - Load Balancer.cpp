#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n];
    int load = 0;
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
        load += arr[i];
    }

    if(load % n != 0) {
        cout<<-1<<endl;
        return 0;
    }

    load = load / n;
    int max_load = 0;
    int diff = 0;
    for(int i = 0; i < n; i++) {
        diff += arr[i] - load;
        int ans = max(diff, -diff);
        max_load = max(max_load, ans);
    }
    cout<<max_load<<endl;
    return 0;
}
