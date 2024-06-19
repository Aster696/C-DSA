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

    // append node - Attach node at the end of the list
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
                cout << "Node successfully appended" << endl;
            }
        }
    }

    // prepend node - Attach node at the start
    void prependNode(Node *n) {
        if(nodeKeyExists(n -> key) != NULL) {
            cout << "Node already exist with key value : " << n -> key << ". Append another node with different key value." << endl;
        }else {
            n -> next = head;
            head = n;
            cout << "Node prepended successfully" << endl;
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

    // Insert node in between list after particular node
    void insertNode(Node *n, int k) {
        // Node *ptr = head;
        // Node *temp = NULL;
        // if(nodeKeyExists(k) == NULL) {
        //     cout << "Key does not exist. Please try with different key" << endl; 
        // }else if(nodeKeyExists(n -> key) != NULL) {
        //     cout << "Node already exist with key value : " << n -> key << ". Append another node with different key value." << endl;
        // }else {
        //     while(ptr != NULL) {
        //         if(ptr -> key == k) {
        //             temp = ptr -> next;
        //             ptr -> next = n;
        //             n -> next = temp;
        //             cout << "Node inserted successfull" << endl;
        //         }
        //         ptr = ptr -> next;
        //     }
        // }

        // another way of doing it
        Node *ptr = nodeKeyExists(k);
        if(ptr == NULL) {
            cout << "Key does not exist. Please try with different key" << endl; 
        }else if(nodeKeyExists(n -> key) != NULL) {
            cout << "Node already exist with key value : " << n -> key << ". Append another node with different key value." << endl;
        }else {
            n -> next = ptr -> next;
            ptr -> next = n;
            cout << "Node inserted successfull" << endl;
        }
    }

    // Delete node by key(unlink node from list)
    void deleteNodeByKey(int k) {
        Node *node = nodeKeyExists(k);
        if(node == NULL) {
            cout << "Key : " <<k <<" does not exist" <<endl;
        }else {
            
        }
    }
};

int main() {
    Node *n1 = new Node(1, 33);
    Node *n2 = new Node(2, 66);
    Node *n3 = new Node(3, 99);
    Node *n0 = new Node(69, 44);
    Node *insertNode = new Node(84, 77);

    SiglyLinkedList si;
    si.appendNode(n1);
    si.appendNode(n2);
    si.appendNode(n3);
    si.displayNodeList();
    si.prependNode(n0);
    si.displayNodeList();
    si.insertNode(insertNode, 45);
    si.displayNodeList();
    return 0;
}