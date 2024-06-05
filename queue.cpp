#include <iostream>
#include <string>


using namespace std;

class Queue {
private:
    int arr[4];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
        for(int i = 0; i < 4; i++) {
            arr[i] = 0;
        }
    }

    bool isEmpty() {
        if(front == -1 && rear == -1) 
            return true;
        return false;
    }

    bool isFull() {
        if(rear == 3) 
            return true;
        return false;
    }

    void enqueue() {
        int value;
        cout << "Enter a value: ";
        cin >> value;
        if(isFull()) {
            cout << "Queue is full" << endl;
            return;
        }else if(front == -1 && rear == -1) {
            front = rear = 0;
        }else {
            rear++;
        }
        arr[rear] = value;
    }

    int dequeue() {
        int value;
        cout << "Enter a value: ";
        cin >> value;
        if(isEmpty()) {
            cout << "Queue is empty" << endl;
            return 0;
        }else if(front == rear) {
            int x = arr[front];
            arr[front] = 0;
            front = rear = -1;
            return x;
        }else {
            int x = arr[front];
            arr[front] = 0;
            front++;
            return x;
        }
    }

    int count() {
        if(isEmpty()) {
            cout << "Queue is empty" << endl;
            return 0;
        }
        return (rear - front + 1);
    }

    void display() {
        cout << "Queue value are: " << endl;
        for(int i = 0; i < 4; i++) {
            cout << arr[i] << endl;
        }
    }

    // menu list
    void menuList() {
        system("cls");
        cout << "Pleaes select your option. Enter 0 for exit" << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. Count()" << endl;
        cout << "6. Display()" << endl;
        cout << "7. Menu()" << endl;
        cout << "8. Clear screen" << endl;
    }

    void menu() {
        menuList();
        int option;
        do
        {
            cout << "Enter your option: ";
            cin >> option;
            switch (option)
            {
            case 0:
                break;
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                isEmpty() ? cout << "Queue is empty" << endl : cout << "Queue is not empty" <<endl;
                break;
            case 4:
                isFull() ? cout << "Queue is full" << endl : cout << "Queue is not full" << endl;
                break;
            case 5:
                count();
                break;
            case 6:
                display();
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
    Queue queue = Queue();
    queue.menu();
    return 0;
}