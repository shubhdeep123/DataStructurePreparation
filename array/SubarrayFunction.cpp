#include <iostream>
#include <unordered_set>
using namespace std;

int sumSubarray(int *arr, int n, int sum) {
    int currSum;

    for (int i=0; i<n; i++) {
        currSum = arr[i];
        for (int j=i+1; j<=n; j++) {
            if (currSum == sum) {
                cout << i << " " << j-1 << endl;
                return 1;
            } 

            if (currSum > sum || j==n) {
                break;
            }
            currSum += arr[j];
        }
    }
    return 0;
}

// This functions tells whether there exists a subarray with sum 0
// O(N^2)
bool isSubarraySumZero(int *arr, int n) {
    int currSum;
    bool flag=false;

    for (int i=0; i<n; i++) {
        currSum = arr[i];
        for (int j=i+1; j<=n; j++) {
            if (currSum == 0) {
                flag = true;
            } else {
                currSum += arr[j];
            }
        }
    }

    return flag;
}

// Using hashing
bool isSubarraySumZero_Optimised(int *arr, int n) {
    unordered_set<int> sumSet;
    int sum = 0;
    for (int i=0; i<n; i++) {
        sum += arr[i];

        if (sum==0 || sumSet.find(sum) != sumSet.end()) {
            return true;
        }

        sumSet.insert(sum);
    }

    return false;
}

int maxProductSubarray(int *arr, int n) {
    int product=1;
    int maxProduct = 1;
    for (int i=0; i<n; i++) {
        product *= arr[i];
        for (int j=i+1; j<n; j++) {
            maxProduct = max(maxProduct,product);
            product *= arr[j];
        }
        maxProduct = max(maxProduct,product);
    }

    return maxProduct;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // int sum;
    // cin >> sum;

    // cout << sumSubarray(arr,n,sum) << endl;
    // cout << isSubarraySumZero(arr,n) << endl;
    cout << maxProductSubarray(arr,n) << endl;
}