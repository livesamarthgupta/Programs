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

node* LCA(node*root, int a, int b) {
    if(root == NULL)
        return NULL;

    if(root->data == a || root->data == b)
        return root;

    node*left = LCA(root->left, a, b);
    node*right = LCA(root->right, a, b);

    if(left != NULL && right != NULL)
        return root;

    if(left != NULL)
        return left;
    return right;
}


int main() {

    node*root = buildTree();
    int a, b;
    cin>>a>>b;
    node*lca = LCA(root, a, b);
    cout<<lca->data<<endl;

}