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


node* buildTreeFromArray(int *a, int s, int e) {
    if(s > e)
        return NULL;
    
    int mid = (s + e) / 2;
    node*newNode = new node(a[mid]);
    newNode->left = buildTreeFromArray(a, s, mid - 1);
    newNode->right = buildTreeFromArray(a, mid + 1, e);

    return newNode;
}

int main() {
    cout<<"Hello World!";
}
