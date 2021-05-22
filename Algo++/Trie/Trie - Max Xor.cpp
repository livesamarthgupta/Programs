#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node*left;
    Node*right;
};

class Trie {
    Node*root;
public:

    Trie() {
        root = new Node();
    }

    void insert(int n) {
        Node*temp = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (n>>i) & 1;

            if(bit == 0) {
                if(temp->left == NULL) {
                    temp->left = new Node();
                }
                temp = temp->left;
            } else {
                if(temp->right == NULL) {
                    temp->right = new Node();
                }
                temp = temp->right;
            }
        }
    }

    int helper(int value) {
        int current = 0;
        Node*temp = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (value>>i) & 1;
            if(bit == 0) {
                if(temp->right != NULL) {
                    temp = temp->right;
                    current += (1 << i);
                } else {
                    temp = temp->left;
                }
            } else {
                if(temp->left != NULL) {
                    temp = temp->left;
                    current += (1 << i);
                } else {
                    temp = temp->right;
                }
            }
        }
        return current;
    }

    int max_xor(int*arr, int n) {
        int max_xor = 0;
        for(int i = 0; i < n; i++) {
            int val = arr[i];
            insert(val);
            int current = helper(val);
            max_xor = max(current, max_xor);
        }
        return max_xor;
    }

};




int main() {
    int arr[] = {3,10,5,25,2,8};
    Trie t;
    cout<<t.max_xor(arr, 6);
}
