#include <iostream>

using namespace std;

void selectionSort() {
    int arr[5] = {83, 55, 1, 33, 6};
    for(int i = 0; i < (sizeof(arr)/sizeof(arr[0])) - 1; i++) {
        int minIndex = i;
        for(int j = i+1; j < (sizeof(arr)/sizeof(arr[0])); j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if(minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
    for(int i = 0; i < (sizeof(arr)/sizeof(arr[0])); i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    selectionSort();
}