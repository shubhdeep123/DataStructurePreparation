#include <iostream>
#include<climits>
using namespace std;

int minJumps_DP(int n,int *arr) {
    int *dp = new int[n + 1];
    for (int i = 0; i < n + 1; i++) {
        dp[i] = -1;
    }
        dp[n] = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] > 0) {
            int temp = INT_MAX;
            for (int j = 1; j <= arr[i] && i + j < n + 1; j++){
                if (dp[i+j] != -1) {
                    temp = min(temp, dp[i + j]);
                }
            }

            if (temp != INT_MAX) {
                dp[i] = temp + 1;
            }
        }
    }

    return dp[0];
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n;i++) {
        cin >> arr[i];
    }
        cout << minJumps_DP(n,arr) << endl;
}