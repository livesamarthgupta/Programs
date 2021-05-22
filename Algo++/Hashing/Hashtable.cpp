#include <iostream>
using namespace std;

template<typename T>
class Node {
public:
    string key;
    T value;
    Node<T>*next;

    Node(string key, T value) {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~Node() {
        if(next != NULL)
            delete next;
    }
};

template<typename T>
class Hashtable {
    Node<T>** table;
    int current_size;
    int table_size;

    int hashFn(string key) {
        int idx = 0;
        int p = 1;
        for(int i = 0; i < key.length(); i++) {
            idx += (key[i] * p) % table_size;
            idx = idx % table_size;
            p = (p * 27) % table_size;
        }
        return idx;
    }

    void rehash() {
        Node<T>** oldTable = table;
        int oldTableSize = table_size;
        table_size = 2 * table_size;
        table = new Node<T>*[table_size];

        for(int i = 0; i < table_size; i++)
            table[i] = NULL;

        current_size = 0;

        //shift elements from oldTable to new table
        for(int i = 0; i < oldTableSize; i++) {
            Node<T>*temp = oldTable[i];

            while(temp != NULL) {
                insert(temp->key, temp->value);
                temp = temp->next;
            }
            //delete each entry
            if(oldTable[i] != NULL)
                delete oldTable[i];
        }
        //delete oldTable
        delete [] oldTable;
    }

public:
    Hashtable(int ts = 7) {
        table_size = ts;
        table = new Node<T>*[table_size];
        current_size = 0;
        for(int i = 0; i < table_size; i++)
            table[i] = NULL;
    }

    void insert(string key, T value) {
        int idx = hashFn(key);
        Node<T>*node = new Node<T>(key, value);

        //insert at the head of idx index of table
        node->next = table[idx];
        table[idx] = node;
        current_size++;

        //rehash when table size increases load factor
        float load_factor = current_size / (1.0 * table_size);
        if(load_factor > 0.7) {
            rehash();
        }
    }

    T* search(string key) {
        int idx = hashFn(key);
        Node<T>*temp = table[idx];

        while(temp != NULL) {
            if(temp->key == key) {
                return &temp->value;
            }
            temp = temp->next;
        }
        return NULL;
    }

    void erase(string key) {
        int idx = hashFn(key);
        Node<T>*keyNode = table[idx];

        while(keyNode->key != key) {
            keyNode = keyNode->next;
        }

        Node<T>*prevNode = table[idx];
        while(prevNode->next != keyNode) {
            prevNode = prevNode->next;
        }
        prevNode->next = keyNode->next;
        delete keyNode;
    }

    T& operator[](string key) {
        T* f = search(key);
        if(f == NULL) {
            T garbage;
            insert(key, garbage);
            f = search(key);
        }
        return *f;
    }

};

int main() {
    Hashtable<int> table;
    table["Hello"] = 1;
    table["World"] = 2;
    cout<<table["Hello"];
}
