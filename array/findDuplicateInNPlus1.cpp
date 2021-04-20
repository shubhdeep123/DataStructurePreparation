#include <iostream>
using namespace std;

int findDuplicate(int *arr, int size) {
    for(int i=0; i<size; i++) {
        for (int j=i+1; j<size; j++) {
            if (!(arr[j]^arr[i])) {
                return arr[j];
            }
        }
    }
    return -1;
}

int main () {
    int arr[] = {2,4,3,5,6,2};
    cout << findDuplicate(arr,6) << endl;
}