#include <iostream>
using namespace std;

void reverseList(node*&head) {
    node*current = head;
    node*prev = NULL;
    node*next;
    while(current != NULL) {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }
    head = prev;
}

node* reverseRecursive(node*head) {
    if(head->next == NULL || head == NULL) {
        return head;
    }

    node*shead = reverseRecursive(head->next);

    head->next->next = head;
    head->next = NULL;
    return shead;
}

int main() {
    cout<<"Hello World!";
}
