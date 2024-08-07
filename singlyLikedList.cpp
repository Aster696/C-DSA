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

    // Insert node in between list after particular node
    void insertNodeAfter(Node *n, int k) {
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
            if(head -> key == k) {
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
            cout << "Node delete successfully. Key : " << k << endl;
        }
    }

    // update node 
    void updateNodeByKey(int k, int data) {
        Node *ptr = nodeKeyExists(k);
        if(ptr == NULL) {
            cout << "Key does not exist" << endl;
        }else {
            ptr -> data = data;
            cout << "Node updated successfully" << endl;
        }
    }

    // display node in list
    void displayNodeList() {
        if(head == NULL){
            cout << "Node list is empty" << endl;
        }else {
            Node *ptr = head;
            while(ptr != NULL) {
            cout << "key : " << ptr -> key << ", data : " << ptr -> data << ", next : " << ptr -> next << endl;
            ptr = ptr -> next;
        }
        }
    }

    // menu list
    void menuList() {
        system("cls");
        cout << "Pleaes select your option. Enter 0 for exit" << endl;
        cout << "1. AppendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. insertNodeAfter()" << endl;
        cout << "4. deleteNodeByKey()" << endl;
        cout << "5. updateNodeByKey()" << endl;
        cout << "6. Display()" << endl;
        cout << "7. Menu()" << endl;
        cout << "8. Clear screen" << endl;
    }

    void menu() {
        menuList();
        int option, key, data;
        do
        {
            Node *n1 = new Node();
            cout << "Enter your option: ";
            cin >> option;
            switch (option)
            {
            case 0:
                break;
            case 1:
                cout << "Enter node key" << endl;
                cin >> n1 -> key;
                cout << "Enter node data" << endl;
                cin >> n1 -> data;
                appendNode(n1);
                break;
            case 2:
                cout << "Enter node key" << endl;
                cin >> n1 -> key;
                cout << "Enter node data" << endl;
                cin >> n1 -> data;
                prependNode(n1);
                break;
            case 3:
                cout << "Enter node key" << endl;
                cin >> n1 -> key;
                cout << "Enter node data" << endl;
                cin >> n1 -> data;
                cout << "Enter the key afterwhich you node to be inserted" << endl;
                cin >> key;
                insertNodeAfter(n1, k);
                break;
            case 4:
                cout << "Enter the key that you want to delete" << endl;
                cin >> key;
                deleteNodeByKey(key);
                break;
            case 5:
                cout << "Enter the key of which you want to update data" << endl;
                cin >> key;
                cout << "Enter the data" << endl;
                cin >> data;
                updateNodeByKey(key, data);
                break;
            case 6:
                displayNodeList();
                break;
            case 7:
                menu();
                break;
            case 8:
                system("cls");
                break;
            default:
                cout << "Invalid input" << endl;
                break;
            }

        } while (option != 0);
        
    } 


};

int main() {

    SiglyLinkedList si;
    si.menu();

    // Node *n1 = new Node(1, 33);
    // Node *n2 = new Node(2, 66);
    // Node *n3 = new Node(3, 99);
    // Node *n0 = new Node(69, 44);
    // Node *insertNode = new Node(84, 77);

    // SiglyLinkedList si;
    // si.appendNode(n1);
    // si.appendNode(n2);
    // si.appendNode(n3);
    // si.displayNodeList();
    // si.prependNode(n0);
    // si.displayNodeList();
    // si.insertNode(insertNode, 3);
    // si.displayNodeList();
    // si.deleteNodeByKey(3);
    // si.displayNodeList();
    // si.updateNodeByKey(2, 1223);
    // si.displayNodeList();
    return 0;
}