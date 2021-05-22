#include <iostream>
using namespace std;


int partition(int arr[], int s, int e) {
    int i = s - 1;
    int j = s;
    int pivot = arr[e];

    while(j <= e - 1) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    swap(arr[e], arr[i + 1]);
    return i + 1;
}

void quick_sort(int arr[], int s, int e) {

    //base case
    if(s >= e)
        return;

    int p = partition(arr, s, e);
    quick_sort(arr, s, p - 1);
    quick_sort(arr, p + 1, e);
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    quick_sort(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
        cout<<endl;
}
