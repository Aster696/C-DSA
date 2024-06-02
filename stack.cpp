#include <ioStream>

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
        if(top >= 4) 
            return true;
        return false;
    }

    // add element in stack
    void push() {
        if(isFull()) {
            cout << "Stack is full" << endl;
        }else {
            int value;
            cout << "Enter a value" << endl;
            cin >> value;
            top++;
            arr[top] = value;
            cout << "Value added to stack successfully!" << endl;
        }
    }

    // delete element from stack
    void pop() {
        if(isEmpty()){
            cout << "Stack is empty" << endl;
        }else {
            arr[top] = 0;
            top--;
            cout << "Element removed successfully from stack" << endl;
        } 
    }

    // search element in stack
    int peek() {

        if(isEmpty()) {
            cout << "Stack is empty" << endl;
            return 0;
        }else {
            int pos;
            cout << "Enter the index number of element you want to search" << endl;
            cin >> pos;
            return arr[pos];
        }
    }

    // check number of element in stack
    void count() {
        if(isEmpty()) {
            cout << "Stack is empty" << endl;
        }else {
            cout << top << endl;
        }
    }

    // update element in stack
    void change() {
        if(isEmpty()) {
            cout << "Stack is empty" << endl;
        }else {
            int pos;
            int value;
            cout << "Enter the index of element you want to update" << endl;
            cin >> pos;
            if(pos > 4 || pos < 0) {
                cout << "Index cannot be more then 4 or less then 0" << endl;
            }else {
                cout << "Enter the new value" << endl;
                cin >> value;
                arr[pos] = value;
            }
        }
    }

    // display all the element in stack
    void display() {
        cout << "List of elements" << endl;
        for(int i = 4; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }

    // menu list
    void menuList() {
        cout << "Pleaes select your option. Enter 0 for exit" << endl;
        cout << "1. Push()" << endl;
        cout << "2. Pop()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. Peek()" << endl;
        cout << "6. Count()" << endl;
        cout << "7. Change()" << endl;
        cout << "8. Display()" << endl;
        cout << "9. Menu" << endl;
        cout << "10. Clear screen" << endl;
    }

    // main menu
    void menu() {
        int option;
        menuList();
        do {
            cin >> option;
            switch (option)
            {
                case 0:
                    break;
                case 1:
                    push();
                    break;
                case 2:
                    pop();
                    break;
                case 3:
                    isEmpty() ? cout << "Stack is empty" << endl : cout << "Stack is not empty" << endl;
                    break;
                case 4:
                    isFull() ? cout << "Stack is full" << endl : cout << "Stack is not full" << endl;
                    break;
                case 5:
                    peek();
                    break;
                case 6:
                    count();
                    break;
                case 7:
                    change();
                    break;
                case 8:
                    display();
                    break;
                case 9:
                    menuList();
                    break;
                case 10:
                    system("cls");
                    break;
                default:
                    cout << "Invaid input" <<endl;
                    break;
            }
            cout << "Enter your option or can exit by pressing 0" << endl;
        }while(option != 0);
    }
};

int main() {
    Stack st = Stack();
    st.menu();
}

