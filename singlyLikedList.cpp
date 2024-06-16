#include <iostream>

using namespace std;

class Node {
public:
    int key, data;
    Node *next;

    Node() {
        key = data = 0;
        next = NULL;
    }

    Node(int k, int d) {
        key = k;
        data = d;
    }
};

class SiglyLinkedList {
public:
    Node *head;

    SiglyLinkedList() {
        head = NULL;
    }

    SiglyLinkedList(Node *n) {
        head = n;
    }

    displayNodeList() {
        head -> key = 1;
        head -> data = 22; 
        head -> next = NULL;
        // SiglyLinkedList(head);
        cout << head -> data << endl;
    }
};

int main() {
    Node *node = new Node();
    SiglyLinkedList si(node);
    si.displayNodeList();
    delete node;
    return 0;
}