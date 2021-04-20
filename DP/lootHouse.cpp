#include<iostream>
#include<climits>
using namespace std;

int maxMoneyLooted_helper(int *arr, int n, int i) {
    if (i>=n) {
        return 0;
    }

    int x = arr[i] + maxMoneyLooted_helper(arr,n,i+2);
    int y = maxMoneyLooted_helper(arr,n,i+1);

    int ans = max(x,y);

    return ans;
}

int maxMoneyLooted(int *arr, int n) {
    return maxMoneyLooted_helper(arr, n, 0);
}

// Time complexity --- O(n)
// Space complexity --- O(n)
int maxMoneyLooted_DP(int *arr, int n) {
    int *dp = new int[n];
    
    dp[0] = arr[0];
    dp[1] = max(arr[0],arr[1]);

    for (int i=2; i<n; i++) {
        dp[i] = max(arr[i]+dp[i-2], dp[i-1]);
    }

    return dp[n-1];
}

// Time complexity --- O(n)
// Space complexity --- O(1)
int maxMoneyLooted_DP_Improved(int *arr, int n) {
    if (n==0) {
        return 0;
    }

    int value1 = arr[0];
    if (n==1) {
        return arr[0];
    }

    int value2 = max(arr[0],arr[1]);
    if (n==2) {
        return value2;
    }

    int max_val = max(arr[0],arr[1]);

    for (int i=2; i<n; i++) {
        max_val = max(arr[i]+value1, value2);
        value1 = value2;
        value2 = max_val;
    }

    return max_val;
}

int main () {
    int arr[] = {5,5,10,100,10,5};
    // BRUTE FORCE
    cout << maxMoneyLooted(arr,6) << endl;
    // DYNAMIC PROGRAMMING
    cout << maxMoneyLooted_DP(arr,6) << endl;
    cout << maxMoneyLooted_DP_Improved(arr,6) << endl;
}