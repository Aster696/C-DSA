#include <iostream>

using namespace std;

class Stack {
    public:
    int top;
    int arr[5];

    Stack() {
        top = -1;
        for(int i = 0; i < 5; i++) {
            arr[i] = 0;
        }
    }

    bool isEmpty() {
        if(top == -1)
            return true;
        else
            return false;
    }

    bool isFull() {
        if(top == 5)
            return true;
        else
            return false;
    }

    void push() {
        int val;
        if(isFull()) {
            cout << "Stack is full" << endl;
        }else {
            cout << "Enter a value: ";
            cin >> val;
            top++;
            arr[top] = val;
            cout << "Element added successfully" << endl;
        }
    }

    int pop() {
        if(isEmpty()) {
            cout << "Stack is empty" << endl;
            return 0;
        }else {
            int popValue = arr[top];
            arr[top] = 0;
            top--;
            cout << "Element removed successfully ";
            return popValue;
        }
    }

    int count() {
        if(isEmpty()) {
            cout << "Stack is empty" << endl;
            return 0;
        }else {
            cout << "Total count of elements: " << top+1;
            return (top+1);
        }
    }

    void peek() {
        int pos;
        if(isEmpty()) {
            cout << "Stack is empty" << endl;
        }else {
            cout << "Enter elements index value: ";
            cin >> pos;
            if(pos < 0 || pos >=5) {
                cout << "Invalid index value" << endl;
            }else {
                cout << "Value: " << arr[pos] << endl;
            }
        }
    }

    void displayAll() {
        cout << endl;
        if(isEmpty()) {
            cout << "Stack is empty" << endl;
        }else {
            cout << "Elements" << endl;
            for(int i = 0; i < 5; i++) {
                cout << arr[i] << endl;
            }
        }

        cout << endl;
    }

    void Menu() {
        string con;
        do{
            int op;
            cout << "1. Display all elements" << endl;
            cout << "2. Add element" << endl;
            cout << "3. Remove element" << endl;
            cout << "4. Total count of elements" << endl;
            cout << "5. Search element" << endl;
            cout << "Enter your option: ";
            cin >> op;

            switch(op) {
                case 1:
                    displayAll();
                    break;
                case 2:
                    push();
                    break;
                case 3:
                    pop();
                    break;
                case 4:
                    count();
                    break;
                case 5:
                    peek();
                    break;
                default:
                    cout << "Invalid option" << endl;
                    break;
            }
            cout << endl;
            cout << "Do you want to continue press 'y' or press 'n' to stop: ";
            cin >> con;
        }while(con == "y");
    }

};

int main()
{
    cout << "Hello world!" << endl;

    Stack stack;
    stack.Menu();

    return 0;
}
