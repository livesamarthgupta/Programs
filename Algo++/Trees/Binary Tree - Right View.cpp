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

node* buildTree() {
    int d;
    cin>>d;
    if(d == -1) {
        return NULL;
    }

    node* newNode = new node(d);
    newNode->left = buildTree();
    newNode->right = buildTree();
    return newNode;
}

void rightView(node*root, int level, int &maxLevel) {
    if(root == NULL)
        return;

    if(maxLevel < level) {
        cout<<root->data<<" ";
        maxLevel = level;
    }

    rightView(root->right, level + 1, maxLevel);
    rightView(root->left, level + 1, maxLevel);
}

int main() {
    node*root = buildTree();
    int maxLevel = -1;
    rightView(root, 0, maxLevel);
}
