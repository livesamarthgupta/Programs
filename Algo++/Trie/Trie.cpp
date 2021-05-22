#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    char data;
    unordered_map<char, Node*> children;
    bool terminal;

    Node(char data) {
        this->data = data;
        terminal = false;
    } 
};

class Trie {
    Node*root;
    int cnt;
public:

    Trie() {
        root = new Node('\0');
        cnt = 0;
    }

    void insert(char *w) {
        Node*temp = root;
        for(int i = 0; w[i] !='\0'; i++) {
            char ch = w[i];
            if(temp->children.count(ch)) {
                temp = temp->children[ch];
            } else {
                Node*newNode = new Node(ch);
                temp->children[ch] = newNode;
                temp = newNode;
            }
        }
        temp->terminal = true;
    }

    bool find(char *w) {
        Node*temp = root;
        for(int i = 0; w[i] != '\0'; i++) {
            char ch = w[i];
            if(temp->children.count(ch) == 0)
                return false;
            else    
                temp = temp->children[ch];
        }
        return temp->terminal;
    }
};

int main() {
    Trie t;
    char w[10];
    char wrd[100];
    cin>>wrd;
    t.insert(wrd);
    // t.insert("hello");
    // t.insert("hell");
    // t.insert("app");
        

    cin>>w;
    cout<<t.find(w);
}
