#include <bits/stdc++.h>
using namespace std;

void buildHeap(vector<int> &v) {
    for(int i = 2; i < v.size(); i++) {
        int idx = i;
        int parent = idx / 2;
        while(idx > 1 && v[idx] > v[parent]) { //to convert to min heap change the condition here
            swap(v[idx], v[parent]);
            idx = parent;
            parent /= 2;
        }
    }
}

void heapify(vector<int> &v, int idx) {
        int left = 2 * idx;
        int right = left + 1;

        int min_idx = idx;
        int last = v.size() - 1;

        if(left <= last && v[left] > v[min_idx]) { //to convert to min heap change the condition here
            min_idx = left;
        }
        if(right <= last && v[right] > v[min_idx]) { //to convert to min heap change the condition here
            min_idx = right; 
        }

        if(min_idx != idx) {
            swap(v[idx], v[min_idx]);
            heapify(v, min_idx);
        }
}

void buildHeapOptimised(vector<int> &v) {
    for(int i = (v.size() - 1 / 2); i >= 1; i--) 
        heapify(v, i);
}

int main() {
    vector<int> v = {-1, 50, 40, 30, 20, 10};
    buildHeapOptimised(v);
    for(int x : v)
        cout<<x<<" ";
}
