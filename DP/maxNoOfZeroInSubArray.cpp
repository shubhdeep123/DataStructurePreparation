#include<iostream>
using namespace std;

int maxNoOfZeroInSubArray (int **arr, int row, int col) {
    int **dp = new int*[row];
    for (int i=0; i<row; i++) {
        dp[i] = new int[col];
    }

    // Base case
    if (row==0 && col==0) {
        return 0;
    }

    // Fill edges col
    for (int i=0; i<col; i++) {
        if (arr[0][i] == 0) {
            dp[0][i] = 1;
        } else {
            dp[0][i] = 0;
        }
    }

    // fill edges row
    for (int i=1; i<row; i++) {
        if (arr[i][0] == 0) {
            dp[i][0] = 1; 
        } else {
            dp[i][0] = 0;
        }
    }

    // fill remaining spots and take out max answer
    int ans = dp[0][0];
    for (int i=1; i<row; i++) {
        for (int j=1; j<col; j++) {
            if (arr[i][j] == 0) {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j],dp[i][j-1])) + 1;
            } else {
                dp[i][j] = 0;
            }
            ans = max(ans,dp[i][j]);
        }
    }

    return ans;
}

int main() {
    int row,col;
    cin >> row >> col;
    int **arr = new int*[row];
    for (int i=0; i<row; i++) {
        arr[i] = new int[col];
        for (int j=0; j<col; j++) {
            cin >> arr[i][j];
        }
    }

    cout << maxNoOfZeroInSubArray(arr,row,col) << endl;
}