#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &v, int idx, int size) {
        int left = 2 * idx;
        int right = left + 1;

        int min_idx = idx;
        int last = size - 1;

        if(left <= last && v[left] > v[min_idx]) { 
            min_idx = left;
        }
        if(right <= last && v[right] > v[min_idx]) { 
            min_idx = right; 
        }

        if(min_idx != idx) {
            swap(v[idx], v[min_idx]);
            heapify(v, min_idx, size);
        }
}

void buildHeap(vector<int> &v) {
    for(int i = (v.size() - 1 / 2); i >= 1; i--) 
        heapify(v, i, v.size());
}

void heapSort(vector<int> &v) {
    buildHeap(v);
    int n = v.size();

    //remove n-1 element from heap
    while(n > 1) {
        swap(v[1], v[n - 1]);
        n--;
        heapify(v, 1, n);
    }
}

int main() {
    vector<int> v = {-1, 50, 40, 30, 20, 10};
    heapSort(v);
    for(int x : v)
        cout<<x<<endl;
}
