#include <iostream>
using namespace std;

class MinMaxStack {
    vector<int> stack;
    vector<int> min_stack;
    vector<int> max_stack;

public:

    void push(int data) {
        int curr_min = data;
        int curr_max = data;
        if(stack.size()) {
            curr_min = min(min_stack[min_stack.size() - 1], curr_min);
            curr_max = max(max_stack[max_stack.size() - 1], curr_max);
        }
        min_stack.push_back(curr_min);
        max_stack.push_back(curr_max);
        stack.push_back(data);
    }

    void pop() {
        stack.pop_back();
        min_stack.pop_back();
        max_stack.pop_back();
    }

    int top() {
        return stack[stack.size() - 1];
    }

    int getMin() {
        return min_stack[min_stack.size() - 1];
    }

    int getMax() {
        return max_stack[max_stack.size() - 1];
    }

};

int main() {
    cout<<"Hello World!";
}
