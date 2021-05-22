#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node*left;
    node*right;

    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

//O(n)
pair<int, int> fastDiameter(node*root) {
    pair<int, int> p;
    if(root == NULL) {
        p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = fastDiameter(root->left);
    pair<int, int> right = fastDiameter(root->right);

    p.first = max(left.first, right.first) + 1; //first -> height, second -> diameter
    p.second = max(left.first + right.first, max(left.second, right.second) );
    return p;
}

int main() {
    cout<<"Hello World!";
}
