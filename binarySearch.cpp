#include <iostream>

using namespace std;

int binarySearch(int arr[], int length, int search_value) {
    int start_value = 0;
    int end_value = length-1;
    while(start_value <= end_value) {
        int mid_value = start_value + (end_value - start_value) / 2;
        if(arr[mid_value] == search_value) {
            cout << "search value index: " << mid_value <<endl;
            return mid_value;
        }else if(arr[mid_value] < search_value) {
            start_value = mid_value + 1;
        }else {
            end_value = mid_value - 1;
        }
    }
    return -1;
}

int main() {
    int length, search_value;
    cout << "Enter the number elements you are going to add" << endl;
    cin >> length;
    int *arr= new int[length];
    cout << "Enter the elements in sorted order: ";
    for(int i = 0; i < length; i++) {
        cin >> arr[i];
    }
    cout << "enter the value you want to search: ";
    cin >> search_value;
    binarySearch(arr, length, search_value);
}