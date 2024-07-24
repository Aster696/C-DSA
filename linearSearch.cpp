#include <iostream>
#include <vector>

using namespace std;

void linearSearch(const vector<int>& arr, int num) {
    bool exist = false;
    int lenght =  arr.size();
    if(lenght > 0) {
        for(int i = 0; i < lenght; i++) {
            if(arr[i] == num) {
                cout << "Value found at position: " << i + 1 << endl;
                exist = true;
                break;
            }
        }
        if(!exist) {
            cout << "Value not found" << endl;
        }
    }else {
        cout << "Array is empty" << endl;
    }
}

int main() {
    int length = 0;
    cout << "Enter the amount of element that you want to store" << endl;
    cin >> length;
    vector<int> arr(length);
    cout << "Enter all the " << length << " values" << endl;
    for(int i = 0; i < length; i++) {
        cin >> arr[i]; 
    }
    int num;
    cout << "Enter the value you want to search" << endl;
    cin >> num;
    linearSearch(arr, num);
    return 0;
}