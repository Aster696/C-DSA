#include <iostream>

using namespace std;

class Node{
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
        next = NULL
    }
};

class CircularLinkedList {
    public:
    Node *head;

    CircularLinkedList() {
        head = NULL
    }

    CircularLinkedList(Node *n) {
        head = n;
    }

    // check if node is null 
    Node *nodeExist(int k) {
        Node temp = NULL;
        Node *ptr = head;
        while(ptr !== NULL) {
            if(prt -> key == k) {
                temp = ptr;
                break;
            }else {
                ptr = ptr -> next;
            }
        }
        delete ptr;
        return temp;
    }

    // append node
    void appendNode(Node *node) {
        Node *ptr = head;
        if(nodeExist(node -> key) != NULL) {
            cout << "Node key already exist" << endl;
        }else {
            while(ptr != NULL) {
                ptr = ptr -> next;
            }
            ptr -> next = node;
            cout << "Node appended successfully" << endl;
        }
    }
};