#include<iostream>
using namespace std;

bool sorted(int* arr, int size) {
    if (size <= 1) {
        return true;
    }

    if (arr[0] < arr[1]) {
        return sorted(arr+1, size-1);
    } else {
        return false;
    }
}

int main() {
    int arr[] = {1,2,1,4,5,6};
    cout << sorted(arr,6) << endl;
    return 0;
}