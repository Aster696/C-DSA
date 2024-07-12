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
};