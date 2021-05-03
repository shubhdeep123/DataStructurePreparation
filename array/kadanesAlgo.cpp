#include <iostream>
using namespace std;

// O(N)
int kadanesAlgo (int *arr, int n) {
    int maxSum = arr[0];
    int currSum = arr[0];
    for (int i=1; i<n; i++) {
        if (currSum >= 0) {
            currSum += arr[i];
        } else {
            currSum = arr[i];
        }

        if (currSum > maxSum) {
            maxSum = currSum;
        }
        
    }

    return maxSum;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << kadanesAlgo(arr,n) << endl;
}