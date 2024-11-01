#include <iostream>

using namespace std;

class InsersionSort {
    public:

    void sort(int arr[], int n) {
        for(int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;

            while(j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            } 
            arr[j + 1] = key;
        }
        display(arr, n);
    }

    void display(int arr[], int n) {
        for(int i = 0; i < n; i++) {
            cout << arr[i] << ", ";
        }
    }
};

int main() {
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    InsersionSort is;
    is.sort(arr, n);
}