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

void printKthLevel(node*root, int k) {
    if(root == NULL)
        return;
    if(k == 0) {
        cout<<root->data<<",";
    }

    printKthLevel(root->left, k-1);
    printKthLevel(root->right, k-1);
    return;
}

int printAtDistanceK(node*root, node*target, int k) {
    if(root == NULL)
        return -1;

    //reaced target node while traversing
    if(root == target) {
        printKthLevel(target, k);
    }

    int DL = printAtDistanceK(root->left, target, k);
    if(DL != -1) {
        //two cases 1- if ancestor is at distance k 2- right of ancestor 
        if(DL + 1 == k) 
            cout<<root->data<<",";
        else 
            printKthLevel(root->right, k - 2 - DL);
        return 1 + DL;
    }

    int DR = printAtDistanceK(root->right, target, k);
    if(DR != -1) {
        //two cases 1- if ancestor is at distance k 2- left of ancestor

        if(DL + 1 == k)
            cout<<root->data<<",";
        else 
            printKthLevel(root->left, k - 2 - DR);
        return 1 + DR;
    }

    return -1;
}

int main() {
    node*root = buildTree();

    node*target = root;

    printAtDistanceK(root, target, 3);


}