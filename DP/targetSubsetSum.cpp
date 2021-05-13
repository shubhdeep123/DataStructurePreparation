#include<iostream>
using namespace std;

bool targetSumSubset(int *arr, int n, int x) {
    bool **dp = new bool*[n + 1];
    for (int i = 0; i < n + 1; i++) {
        dp[i] = new bool[x + 1];
    }

    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < x + 1; j++) {
            if (i==0 && j==0) {
                dp[i][j] = true;
            }
            else if (i == 0)
            {
                dp[i][j] = false;
            }
            else if (j == 0)
            {
                dp[i][j] = true;
            }
            else
            {
                if (dp[i - 1][j] == true) {
                    dp[i][j] = true;
                } else {
                    int val = arr[i - 1];
                    if(dp[i-1][j-val]==true) {
                        dp[i][j] = true;
                    }
                }
            }
        }
    }

    return dp[n][x];
}

int main() {
    int n,x;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> x;

    cout << targetSumSubset(arr, n, x) << endl;
}