#include <iostream>

using namespace std;

class Stack {
private:

    int arr[5];
    int top = -1;

public:
    Stack() {
        for(int i = 0; i < 5; i++) {
            arr[i] = 0;
        }
    }

    // check if stack is empty 
    bool isEmpty() {
        if(top < 0)
            return true;
        return false;
    }

    // check if stack is full
    bool isFull() {
        if(top >= 5) 
            return true;
        return false;
    }

    // add data in stack
    void push(int value) {
        if(isFull()) {
            cout << "Stack is full" << endl;
        }else {
            top++;
            arr[top] = value;
            cout << "Value added to stack successfully!" << endl;
        }
    }

    // delete data from stack
    void pop() {
        if(isEmpty()){
            cout << "Stack is empty" << endl;
        }else {
            arr[top] = 0;
            top--;
        } 
    }

    // search data in stack

};

int main() {
    Stack st = Stack();
    st.push(4);
}

