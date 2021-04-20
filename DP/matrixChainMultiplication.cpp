#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int noOfOperations(int *arr, int s, int e) {
    if (s==e) {
        return 0;
    }

    if (s==e-1) {
        return 0;
    }

    int ans;
    for (int i=s+1; i<e; i++) {
        int fisrtAttempt = noOfOperations(arr,s,i);
        int secondAttempt = noOfOperations(arr,i,e);
        int temp = arr[s]*arr[i]*arr[e] + fisrtAttempt + secondAttempt;
        ans = min(ans,temp);
    }

    return ans;
}

int noOfOperations_DP (int *arr, int n) {
    n+=1;

    vector<vector<int>> dp(n,vector<int>(n));

    for (int i=1; i < n; i++) {
        dp[i][i] = 0;
    }

    for (int L=2; L<n; L++) {
        for (int i=1; i<n-L+1; i++) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (int k=i; k<=j-1; k++) {
                int q = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                }
            }
        }
    }

    return dp[1][n-1];
}

int main() {
    int arr[] = {10,15,20,25};
    // Recursive (BRUTE FORCE)
    cout << noOfOperations(arr,0,3) << endl;
    // Dynamic Programming
    cout << noOfOperations_DP(arr,3) << endl;
}