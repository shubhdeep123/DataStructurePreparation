#include<iostream>
#include<climits>
using namespace std;

int rainwaterTrapping(int *arr, int n) {
    int *left = new int[n];
    int *right = new int[n];

    int maxVal = INT_MIN;
    for (int i=0; i<n; i++) {
        maxVal = max(maxVal,arr[i]);
        left[i] = maxVal;
    }

    maxVal = INT_MIN;
    for (int i=n-1; i>=0; i++) {
        maxVal =max(maxVal,arr[i]);
        right[i] = maxVal;
    }
    
    int ans=0;
    for (int i=0; i<n; i++) {
        ans += min(left[i],right[i]) - arr[i];
    }

    delete [] left;
    delete [] right;
    return ans;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << rainwaterTrapping(arr,n) << endl;
    
    return 0;
}