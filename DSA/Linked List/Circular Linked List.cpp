#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(node*&head, int data) {
    node*newNode = new node(data);
    node*temp = head;
    newNode->next = head;
    if(temp != NULL) {
        while(temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        head = newNode;
    } else {
        head = newNode;
        newNode->next = newNode;
    }
}

node* getNode(node*head, int data) {
    node*temp = head;
    while(temp->next != head) {
        if(temp->data == data)
            return temp;
        temp = temp->next; 
    }
    if(temp->data == data)
        return temp;
    return NULL;
}

void deleteNode(node*&head, int data) {
    node*del = getNode(head, data);
    if(del == NULL)
        return;

    if(del == head)
        head = head->next;

    node*temp = head;
    while(temp->next != del) {
        temp = temp->next;
    }

    temp->next = del->next;
    delete del;
}

void printList(node*head) {
    node*temp = head;
    while(temp->next != head) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}

int main() {    
    node*head = NULL;
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    printList(head);
    deleteNode(head, 10);
    printList(head);


    return 0;
}