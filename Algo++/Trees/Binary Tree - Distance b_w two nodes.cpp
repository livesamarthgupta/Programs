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

int search(node*root, int key, int level) {
    if(root == NULL)
        return -1;

    if(root->data == key)
        return level;

    int left = search(root->left, key, level + 1);
    if(left != -1)
        return left;
    return search(root->right, key, level + 1);
}

int distance(node*root, int a, int b) {
    node* lca = LCA(root, a, b);

    int l1 = search(lca, a, 0);
    int l2 = search(lca, b, 0);

    return l1 + l2;
}


int main() {

    node*root = buildTree();
    int a, b;
    cin>>a>>b;
    int dis = distance(root, a, b);
    cout<<dis<<endl;

}