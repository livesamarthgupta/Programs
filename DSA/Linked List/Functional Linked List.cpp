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
    if(head == NULL) {
        head = new node(data);
        return;
    }

    node *n = new node(data);
    n->next = head;
    head = n;
}

void insertAtTail(node*&head, int data) {
    if(head == NULL) {
        insertAtHead(head, data);
        return;
    }

    node*tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
    }

    node *n = new node(data);
    tail->next = n;

}

void insertInMiddle(node*&head, int pos, int data) {
    if(head == NULL || pos == 0) {
        insertAtHead(head, data);
    }
    node*temp = head;
    int jumps = 1;
    while(jumps < pos - 1) {
        temp = temp->next;
        jumps++;
    }

    node *n = new node(data);
    n->next = temp->next;
    temp->next = n;
}

void deleteHead(node*&head) {
    if(head == NULL)
        return;
    
    node*temp = head->next;
    delete head;
    head = temp;
}

bool search(node*head, int key) {
    while(head != NULL) {
        if(head->data == key)
            return true;
        head = head->next;
    }
    return false;
}

bool searchRecursive(node*head, int key) {
    if(head == NULL)
        return false;
    
    if(head->data == key)
        return true;
    else 
        return searchRecursive(head->next, key);
}

node* take_input(int n = -1) {
    if(n > -1) {
        node*head = NULL;
        int d;
        if(n == 0) return head;
        while(n--) {
            cin>>d;
            insertAtHead(head, d);
        } 
        return head;
    }

    node*head = NULL;
    int d;
    cin>>d;
    while(d != -1) {
        insertAtHead(head, d);
        cin>>d;
    } 
    return head;
}

void printList(node*head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

ostream& operator<<(ostream &os, node*head) {
    printList(head);
    return os;
}

istream& operator>>(istream &is, node*&head) {
    head = take_input();
    return is;
}

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

node* midPoint(node*head) {
    if(head == NULL || head->next == NULL)
        return head;

    node*slow = head;
    node*fast = head;

    while(fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

node* kthElementFromEnd(node*head, int k) {
    if(head == NULL || head->next == NULL)
        return head;

    node*slow = head;
    node*fast = head;
    while(k--) {
        fast = fast->next;
    }

    while(fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

void clearList(node*head) {
    while(head != NULL) {
        node*temp = head->next;
        delete head;
        head = temp;
    }
}

node* merge(node*a, node*b) {
    if(a == NULL) {
        return b;
    }
    if(b == NULL) {
        return a;
    }

    node*c;
    if(a->data < b->data) {
        c = a;
        c->next = merge(a->next, b);
    } else {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

node* mergeSort(node*head) {
    if(head == NULL || head->next = NULL)
        return head;

    node*mid = midPoint(head);
    node*a = head;
    node*b = mid->next;

    mid->next = NULL;

    a = mergeSort(a);
    b = mergeSort(b);

    node*c = merge(a, b);
    return c;
}

bool detectCycleAndDelete(node*head) {
    node*slow = head;
    node*fast = head;
    bool isPresent = false;

    while(fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) {
            isPresent = true;
            break;
        }
    }

    if(isPresent) {
        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        node *join = slow;
        while(fast->next != join) {
            fast = fast->next;
        }
        fast->next = NULL;
    }
    return isPresent;
}

Node *intersectionOfTwoLinkedLists(Node *l1, Node *l2) {
    unordered_set<Node*> hastable;
    Node *temp = l1;
    while(temp != NULL) {
        hastable.insert(temp);
        temp = temp->next;
    }

    temp = l2;
    while(temp != NULL) {
        if(hastable.find(temp) == hastable.end())
            hastable.insert(temp);
        else 
            return temp;
        temp = temp->next;
    }
    return NULL;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        node *head1 = take_input(n);
        cin>>n;
        node*head2 = take_input(n);
        // cout<<head1<<head2;
        head1 = reverseRecursive(head1);
        head2 = reverseRecursive(head2);
        // cout<<head1<<head2;
        node *merged = merge(head1, head2);
        cout<<merged;
        clearList(merged);
    }
}
