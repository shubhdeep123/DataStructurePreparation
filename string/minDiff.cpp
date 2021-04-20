#include<iostream>
#include <algorithm>
using namespace std;

int getMinDiff(int *arr, int size, int k) {
    sort(arr, arr+size);
    int diff = arr[size-1] - arr[0];
    int big = arr[size-1] - k;
    int small = arr[0] + k;

    for (int i=1; i<size-1; i++) {
        int minus = arr[i] - k;
        int add = arr[i] + k;
        if (add > big) {
            big = add;
        } else if (minus < small) {
            small = minus;
        }
    }

    return min(diff, big-small);
}

int main(){
    int size;
    cin >> size;
    int k;
    cin >> k;

    int *arr = new int[size];
    for (int i=0; i<size; i++) {
        cin >> arr[i];
    }

    cout << getMinDiff(arr,size,k) << endl;
    delete [] arr; 
}