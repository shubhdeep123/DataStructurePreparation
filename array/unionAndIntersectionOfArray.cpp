#include<iostream>
using namespace std;

void printUnion(int arr1[], int arr2[], int n, int m) {
    int i=0, j=0;

    while (i<n && j<m) {
        if (arr2[j] < arr1[i]) {
            cout << arr2[j++] << " ";
        } else if (arr1[i] < arr2[j]) {
            cout << arr1[i++] << " ";
        } else {
            cout << arr2[j++] << " ";
            i++;
        }
    }

    while(i<n) {
        cout << arr1[i++] << " ";
    }

    while (j<m) {
        cout << arr2[j++] << " ";
    }
}

int main() {
    int arr1[] = {1,2,4,5,6};
    int arr2[] = {2,3,5,7};

    printUnion(arr1,arr2,5,4);

    return 0;
    
}