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

void inorderPrint(node*root) {
    if(root == NULL)
        return;

    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

node* insertInBST(node*root, int data) {
    if(root == NULL)
        return new node(data);

    if(root->data >= data) 
        root->left = insertInBST(root->left, data);
    else 
        root->right = insertInBST(root->right, data);

    return root;
}

node* buildTree() {
    node* root = NULL;
    int d;
    cin>>d;
    while(d != -1) {
        root = insertInBST(root, d);
        cin>>d;
    }
    return root;
}

bool search(node*root, int data) {
    if(root == NULL)
        return false;

    if(data == root->data)
        return true;

    if(data <= root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

node* deleteInBST(node*root, int data) {
    if(root == NULL)
        return NULL;
    else if(root->data > data) {
        root->left = deleteInBST(root->left, data);
        return root;
    } else if(root->data == data) {
        //3 cases

        //1. case 1 with 0 child
        if(root->left == NULL && root->right == NULL) {
            return NULL;
        }

        //2. case with 1 child
        if(root->left != NULL && root->right == NULL) {
            node*temp = root->left;
            delete root;
            return temp;
        } 
        if(root->right != NULL && root->left == NULL) {
            node*temp = root->right;
            delete root;
            return temp;
        }

        //3. case with 2 child
        if(root->left != NULL && root->right != NULL) {
            //on right subtree, traverse to last left node
            node*replace = root->right;
            while(replace->left != NULL) {
                replace = replace->left;
            }
            root->data = replace->data;
            root->right = deleteInBST(root->right, replace->data);
            return root;
        }



    } else {
        root->right = deleteInBST(root->right, data);
        return root;
    }
    return NULL;
}

bool isBST(node*root, int minV = INT_MIN, int maxV = INT_MAX) {
    if(root == NULL)
        return true;
    if(root->data <= maxV && root->data >= minV && isBST(root->left, minV, root->data) && isBST(root->right, root->data, maxV))
        return true;
    return false;
}

class LinkedList {
public:
    node*head;
    node*tail;
};

LinkedList flatten(node*root) {
    LinkedList l;

    if(root == NULL) {
        l.head = l.tail = NULL;
        return l;
    }

    //leaf node
    if(root->left == NULL && root->right == NULL) {
        l.head = l.tail = root;
        return l;
    }

    //left is not null 
    if(root->left != NULL && root->right == NULL) {
        LinkedList leftLL = flatten(root->left);
        leftLL.tail->right = root; //right is used as next

        l.head = leftLL.head;
        l.tail = root;
        return l;
    }

    //right is not null
    if(root->right != NULL && root->left == NULL) {
        LinkedList rightLL = flatten(root->right);
        root->right = rightLL.head;

        l.head = root;
        l.tail = rightLL.tail;
        return l;
    }

    //left and right are not null
    LinkedList leftLL = flatten(root->left);
    LinkedList rightLL = flatten(root->right);

    leftLL.tail->right = root;
    root->right = rightLL.head;

    l.head = leftLL.head;
    l.tail = rightLL.tail;
    return l;
}

int main() {
    node*root = buildTree();
    // inorderPrint(root);
    int s;
    cin>>s;
    BFS(root);
    // cout<<endl;
    // root = deleteInBST(root, s);
    // BFS(root);
    // cout<<isBST(root);
    LinkedList ll = flatten(root);
    node*head = ll.head;
    while(head != NULL) {
        cout<<head->data<<" -> ";
        head = head->right;
    }
}
