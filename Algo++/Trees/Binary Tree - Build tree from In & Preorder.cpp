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

void BFS(node*root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node *front = q.front();

        if(front == NULL) {
            cout<<endl;
            q.pop();
            if(!q.empty()) {
                q.push(NULL);
            }
        } else {
            q.pop();
            cout<<front->data<<" ";
        
            if(front->left) {
                q.push(front->left);
            }

            if(front->right) {
                q.push(front->right);
            }
        }
    }
}

node* buildTreeFromTraversal(int *inorder, int *preorder, int s, int e) {
    static int i = 0;
    if(s > e)
        return NULL;

    node*root = new node(preorder[i]);

    int index = -1;
    for(int j = s; j <= e; j++) {
        if(inorder[j] == preorder[i]) {
            index = j;
            break;
        }
    }

    i++;
    root->left = buildTreeFromTraversal(inorder, preorder, s, index - 1);
    root->right = buildTreeFromTraversal(inorder, preorder, index + 1, e);

    return root;
}


int main() {
    int inorder[] = {3,2,8,4,1,6,7,5};
    int preorder[] = {1,2,3,4,8,5,6,7};
    int n = sizeof(inorder)/sizeof(int);

    node*root = buildTreeFromTraversal(inorder, preorder, 0, n - 1);
    BFS(root);
}
