#include <bits/stdc++.h>
using namespace std;

class Heap {
    vector<int> v;
    bool minHeap;

    bool compare(int a, int b) {
        if(minHeap) 
            return a < b;
        else 
            return a > b;
    }

    void heapify(int idx) {
        int left = 2 * idx;
        int right = left + 1;

        int min_idx = idx;
        int last = v.size() - 1;

        if(left <= last && compare(v[left], v[min_idx])) {
            min_idx = left;
        }
        if(right <= last && compare(v[right], v[min_idx])) {
            min_idx = right;
        }

        if(min_idx != idx) {
            swap(v[idx], v[min_idx]);
            heapify(min_idx);
        }
    }

public:

    Heap( bool type = true, int default_size = 10) {
        v.reserve(default_size);
        v.push_back(-1);
        minHeap = type;
    }

    void push(int data) {
        v.push_back(data);
        int idx = v.size() - 1;
        int parent = idx / 2;

        //check parent satisfies heap property
        while(idx > 1 && compare(v[idx], v[parent])) {
            swap(v[idx], v[parent]);
            idx = parent;
            parent /= 2;
        }
    }

    int top() {
        return v[1];
    }

    void pop() {
        int last = v.size() - 1;
        //swap min/max element with last element and remove
        swap(v[1], v[last]);
        v.pop_back();
        heapify(1);
    }

    bool empty() {
        return v.size() == 1;
    }

};


int main() {
    int n;
    cin>>n;
    Heap h;
    for(int i = 0; i < n; i++) {
        int no;
        cin>>no;
        h.push(no);
    }

    while(!h.empty()) {
        cout<<h.top()<<" ";
        h.pop();
    }

    cout<<endl;

    Heap h2(false);

    for(int i = 0; i < n; i++) {
        int no;
        cin>>no;
        h2.push(no);
    }

    while(!h2.empty()) {
        cout<<h2.top()<<" ";
        h2.pop();
    }

}
