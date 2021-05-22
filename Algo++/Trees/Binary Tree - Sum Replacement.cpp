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

int replaceSum(node*root) {
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL) {
        return root->data;
    }

    int leftSum = replaceSum(root->left);
    int rightSum = replaceSum(root->right);

    int temp = root->data;
    root->data = leftSum + rightSum;
    return temp + root->data;
}


int main() {
    cout<<"Hello World!";
}
