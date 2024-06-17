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

    // check if node exist and return null if does not
    Node *nodeExists(int k) {
        Node *temp = NULL;
        Node *ptr = head;

        while(ptr != NULL) {
            if(ptr -> key == k) {
                temp = ptr;
            }
            ptr = ptr -> next;
        }

        return temp;
    }

    void displayNodeList() {
        Node *ptr = head;
        while(ptr != NULL) {
            if(ptr -> next != NULL) {
                cout << "key : " << ptr -> key << ", data : " << ptr -> data << ", next : " << ptr -> next << endl;
                ptr = ptr -> next;
            }
        }
    }
};

int main() {
    Node *n1 = new Node(1, 33);
    Node *n2 = new Node(2, 66);
    Node *n3 = new Node(3, 99);
    SiglyLinkedList si(n1);
    n1 -> next = n2;
    n2 -> next = n3;
    si.displayNodeList();
    return 0;
}