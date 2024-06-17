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
        next = NULL;
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
    Node *nodeKeyExists(int k) {
        Node *temp = NULL;
        Node *ptr = head;

        while(ptr != NULL) {
            if(ptr -> key == k) {
                temp = ptr;
            }
            ptr = ptr->next;
        }

        return temp;
    }

    // append node
    void appendNode(Node *n) {
        if(nodeKeyExists(n -> key) != NULL) {
            cout << "Node already exist with key value : " << n -> key << ". Append another node with different key value." << endl;
        }else {
            if(head == NULL) {
                head = n;
            }else {
                Node *ptr = head;
                while(ptr -> next != NULL) {
                    ptr = ptr -> next;
                }
                ptr -> next = n;
            }
        }
    }

    // display node in list
    void displayNodeList() {
        Node *ptr = head;
        while(ptr != NULL) {
            cout << "key : " << ptr -> key << ", data : " << ptr -> data << ", next : " << ptr -> next << endl;
            ptr = ptr -> next;
        }
    }
};

int main() {
    Node *n1 = new Node(1, 33);
    Node *n2 = new Node(2, 66);
    Node *n3 = new Node(3, 99);
    SiglyLinkedList si;
    si.appendNode(n1);
    si.appendNode(n2);
    si.appendNode(n3);
    si.displayNodeList();
    return 0;
}