#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {
    Node* root;
public: 

    BST() {
        root = NULL;
    }

    Node* insertInBST(Node*root, int data) {
        if(root == NULL)
            return new Node(data);

        if(root->data > data) {
            root->left = insertInBST(root->left, data);
        } else {
            root->right = insertInBST(root->right, data);
        }
        return root;
    }

    void buildTree() {
        int d;
        cin>>d;
        while(d != -1) {
            this->root = insertInBST(this->root, d);
            cin>>d;
        }
    }

    void BFS() {
        queue<Node*> q;
        q.push(this->root);
        while(!q.empty()) {
            Node *temp = q.front();
            cout<<temp->data<<" ";
            q.pop();
            if(temp->left != NULL) 
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
        }
    }
};


int main() {
    BST t;
    t.buildTree();
    t.BFS();
}
