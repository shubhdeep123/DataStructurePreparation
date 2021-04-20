#include<iostream>
using namespace std;

void merge (int* input, int si, int ei) {
    int size = ei-si+1;
    int mid = (si + ei)/2;
    int* out = new int[size];

    int i = si;
    int j = mid+1;
    int k = 0;

    while (i<=mid && j<=ei) {
        if (input[i] < input[j]) {
            out[k] = input[i++];
        } else if (input[j] < input[i]) {
            out[k] = input[j++];
        } else {
            out[k] = input[i++];
            j++;
        }
        k++;
    }

    while (i<=mid) {
        out[k++] = input[i++]; 
    } 

    while (j<=ei) {
        out[k++] = input[j++];
    }

    int m=0;
    for (int l=si; l<=ei; l++) {
        input[l] = out[m];
        m++;
    }

    delete [] out;
}

void mergeSort(int* input, int si, int ei) {
    if (si >= ei) {
        return;
    }

    int mid = (si+ei)/2;
    mergeSort(input,si,mid);
    mergeSort(input,mid+1,ei);
    merge(input,si,ei);
}


int main () {
    int arr[] = {1,5,3,64,32,12,43,4};
    mergeSort(arr,0,7);

    for (int i=0; i<8; i++) {
        cout << arr[i] << " ";
    } 
    cout << endl;

    return 0;
}