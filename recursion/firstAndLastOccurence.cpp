#include<iostream>
using namespace std;

int firstOccurence(int* arr, int size, int x) {
    if (size == 0) {
        return -1 ;
    }

    int smallAns = firstOccurence(arr+1,size-1,x);

    if (arr[0] != x) {
        if (smallAns == -1) {
            return -1;
        } else {
            return smallAns + 1;
        }
    } else {
        return 0;
    }
}

int main() {
    int arr[] = {2,3,4,5,4,6,4};
    cout << firstOccurence(arr,7,4) << endl;
    return 0;
}