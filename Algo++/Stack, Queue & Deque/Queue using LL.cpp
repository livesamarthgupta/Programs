#include <bits/stdc++.h>
using namespace std;

class Queue {
private:
    list<int> q;
    int cs;
public:
    Queue() {
        cs = 0;
    }

    void push(int data) {
        q.push_back(data);
        cs++;
    }

    bool empty() {
        return cs == 0;
    }

    void pop() {
        if(!empty()) {
            q.pop_front();
            cs--;
        }
    }

    int front() {
        return q.front();
    }
};

int main() {
    cout<<"Hello World!";
}
