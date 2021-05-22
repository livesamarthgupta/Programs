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

void preorderPrint(node*root) {
    if(root == NULL) {
        return;
    }

    cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
} 

void inoderPrint(node*root) {
    if(root == NULL)
        return;

    inoderPrint(root->left);
    cout<<root->data<<" ";
    inoderPrint(root->right);
}

void postorderPrint(node*root) {
    if(root == NULL)
        return;

    postorderPrint(root->left);
    postorderPrint(root->right);
    cout<<root->data<<" ";
}

int height(node*root) {
    if(root == NULL)
        return 0;
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

void printKthLevel(node*root, int k) {
    if(root == NULL)
        return;
    if(k == 1) {
        cout<<root->data<<" ";
    }

    printKthLevel(root->left, k-1);
    printKthLevel(root->right, k-1);
    return;
}

//O(n^n)
void levelOrderPrint(node*root) {
    int h = height(root);

    for(int i = 1; i <= h; i++) {
        printKthLevel(root, i);
        cout<<endl;
    }
}

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

int countNode(node*root) {
    if(root == NULL) 
        return 0;

    return 1 + countNode(root->left) + countNode(root->right);
}

int sumNode(node*root) {
    if(root == NULL)
        return 0;
    return root->data + sumNode(root->left) + sumNode(root->right);
}

//O(n^n)
int diameter(node*root) {
    if(root == NULL)
        return 0;

    int h1 = height(root->left);
    int h2 = height(root->right);
    int op1 = h1 + h2;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);

    return max(op1, max(op2, op3));
}


pair<int, bool> isBalanced(node*root) {
    pair<int, bool> p;
    if(root == NULL) {
        p.first = 0;
        p.second = true;
        return p;
    }

    pair<int, bool> left = isBalanced(root->left);
    pair<int, bool> right = isBalanced(root->right);

    p.first = left.first + right.first + 1; //first -> height, second -> balance

    if(abs(left.first - right.first) <= 1 && left.second && right.second) {
        p.second = true;
    } else {
        p.second = false;
    }
    return p;
}



int main() {
    // node* root = buildTree();
    // preorderPrint(root);
    // cout<<endl;
    // inoderPrint(root);
    // cout<<endl;
    // postorderPrint(root);
    // cout<<endl;
    // cout<<height(root);
    // cout<<endl;
    // levelOrderPrint(root);
    // BFS(root);
    // cout<<countNode(root)<<endl;
    // cout<<sumNode(root)<<endl;
    // cout<<diameter(root)<<endl;
    // pair<int, int> dia = fastDiameter(root);
    // cout<<dia.second<<endl;
    // replaceSum(root);
    // pair<int, bool> balance = isBalanced(root);
    // cout<<balance.second<<endl;
    int arr[] = {1,2,3,4,5,6,7};
    int n = 7;
    node*root = buildTreeFromArray(arr, 0, n - 1);
    BFS(root);
}
