#include <iostream>

using namespace std;

class circularQueue {
private:
    int arr[5], front, rear;
public:
    circularQueue() {
        front, rear = -1;
        for(int i = 0; i < 5; i++) {
            arr[i] = 0;
        }
    }

    bool isEmpty() {
        return front == -1 && rear == -1 ? true : false;
    }

    bool isFull() {
        return (rear + 1) % size(arr) == front ? true : false;
    }

    void enqueue(){
        if(isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        int value;
        cout << "Enter a value: ";
        cin >> value;
        if(front == -1 && rear == -1) {
            front, rear = 0;
        }else {
            rear = (rear + 1) % size(arr);
        }
        arr[rear] = value;
    }

    int dequeue() {
        if(isEmpty()) {
            cout << "Queue is empty" << endl;
            return 0;
        }else if(rear == front) {
            arr[rear] = 0;
            rear, front = -1;
        }else {
            int x = arr[front] = 0;
            cout << "Value removed is: " << x << endl;
            front = (front + 1) % size(arr);
        }
        return 0;
    }

    int count() {
        return 0;
    }

    void display() {
        
    }

    int mod() {
        int pos;
        cout << "Enter position" << endl;
        cin >> pos;
        cout << "result: " << pos % size(arr) << endl;
        return 0;
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
            case 9:
                mod();
                break;
            
            default:
                cout << "Invalid input" << endl;
                break;
            }

        } while (option != 0);
        
    } 
};