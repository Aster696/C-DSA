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
        next = NULL;
    }
};

class CircularLinkedList {
    public:
    Node *head;

    CircularLinkedList() {
        head = NULL;
    }

    CircularLinkedList(Node *n) {
        head = n;
    }

    // check if node is null 
    Node *nodeExist(int k) {
        Node* temp = NULL;
        Node* ptr = head;
        if (head != NULL) {
            do {
                if (ptr->key == k) {
                    temp = ptr;
                    break;
                }
                ptr = ptr->next;
            } while (ptr != head);
        }
        return temp;
    }

    // append node
    void appendNode(Node *node) {
        Node *ptr = head;
        if(nodeExist(node -> key) != NULL) {
            cout << "Node key already exist" << endl;
        }else {
            if(head == NULL) {
                head = node;
                head -> next = head;
            } else {
                while(ptr -> next != head) {
                    ptr = ptr -> next;
                }
                node -> next = head;
                ptr -> next = node;

            }
            cout << "Node appended successfully" << endl;
        }
    }

    // update node using key
    void updateNodeByKey(int k, int d) {
        if(head != NULL) {
            Node *ptr = nodeExist(k);
            if(ptr != NULL) {
                ptr -> data = d;
                cout << "Node updated successfully" << endl;
            }else {
                cout << "Node key does not exist key: "<< ptr -> key << endl;
            }
        }else {
            cout << "Node list is empty" << endl;
        }
    }

    // delete node by key
    void deleteNodeByKey(int k) {
        Node *node = nodeExist(k);
        if(head != NULL) {
            if(head -> k == k) {
                head = head -> next;
            }else {
                Node *ptr = head;
                while(ptr -> next != NULL) {
                    if(ptr -> next == node){
                       ptr -> next = node -> next;
                       delete node;
                       break;
                    }
                    ptr = ptr -> next;
                }
            }
        }else {
            cout << "Node list is empty" << endl;
        }
    }

    // display node in list
    void displayNodeList() {
        if(head == NULL){
            cout << "Node list is empty" << endl;
        }else {
            Node *ptr = head;
            do {
                cout << "key : " << ptr -> key << ", data : " << ptr -> data << ", next : " << ptr -> next << endl;
                ptr = ptr -> next;
            } while(ptr != head);
        }
    }
};

int main() {
    Node *n1 = new Node(1, 335);
    Node *n2 = new Node(2, 422);
    Node *n3 = new Node(3, 422);
    Node *n4 = new Node(4, 606);
    Node *n5 = new Node(5, 900);
    CircularLinkedList cl;
    cl.appendNode(n1);
    cl.appendNode(n2);
    cl.appendNode(n3);
    cl.appendNode(n4);
    cl.appendNode(n5);
    cl.displayNodeList();
    cl.updateNodeByKey(3, 253);
    cl.displayNodeList();
    return 0;
}