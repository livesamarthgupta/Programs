#include <bits/stdc++.h>
using namespace std;

class Queue {
    int *q;
    int f, r, csize, msize;
public:
    Queue(int size = 5) {
        msize = size;
        csize = 0;
        q = new int[size];
        f = 0;
        r = msize - 1;
    }

    bool full() {
        return csize == msize;
    }

    void push(int data) {
        if(!full()) {
            r = (r + 1) % msize;
            q[r] = data;
            csize++;
        }
    }

    bool empty () {
        return csize == 0;
    }

    void pop() {
        if(!empty()) {
            f = (f + 1) % msize;
            csize--;
        }
    }

    int front() {
        return q[f];
    }

    ~Queue() {
        if(q != NULL) {
            delete [] q;
            q = NULL;
        }
    }
};

int main() {
    Queue q;
    for(int i = 0; i < 6; i++) {
        q.push(i);
    }

    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }
}
