#include<iostream>
using namespace std;

int knapsack(int *valueArr, int *weightArr, int n, int weight) {
    if (n==0 || weight==0) {
        return 0;
    }

    int taken, notTaken;
    if (weightArr[n-1] > weight) {
        return knapsack(valueArr,weightArr,n-1,weight);
    } else {
        return max(valueArr[n-1] + knapsack(valueArr,weightArr,n-1,weight-weightArr[n-1]), 
        knapsack(valueArr,weightArr,n-1,weight));
    }
}

int knapsack_Mem(int *val, int *wt, int n, int W, int **output) {
    // BASE CASE
    if (n==0 || W==0) {
        return 0;
    }

    // Check if answer exists
    if (output[n][n] != -1) {
        return output[n][n];
    }

    // Recursive calls and save answers
    if (wt[n-1] > W) {
        output[n][n] = knapsack(val,wt,n-1,W);
    } else {
        output[n][n] = max(val[n-1] + knapsack(val,wt,n-1,W-wt[n-1]), 
        knapsack(val,wt,n-1,W));
    }

    return output[n][n];
} 

int knapsack_DP(int *val, int *wt, int n, int W) {
    int **output = new int*[n+1];
    for (int i=0; i<=n; i++) {
        output[i] = new int[W+1];
    }

    // Fill cells
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=W; j++) {
            if (i==0 || j==0) {
                output[i][j] = 0;
            } else {
                if (wt[i-1] > j) {
                    output[i][j] = output[i-1][j];
                } else {
                    output[i][j] = max(val[i-1] + output[i-1][j-wt[i-1]], output[i-1][j]);
                }
            }
        }
    }

    return output[n][W];
}

int main() {
    int val[] = {60,100,120};
    int wght[] = {10,20,30}; 
    // BRUTE FORCE
    cout << knapsack(val,wght,3,50) << endl;
    // MEMOIZATION
    int **arr = new int*[4];
    for (int i=0; i<=3; i++) {
        arr[i] = new int[4];
        for (int j=0; j<=3; j++) {
            arr[i][j] = -1;
        }
    }
    cout << knapsack_Mem(val,wght,3,50,arr) << endl;
    // DYNAMIC PROGRAMMING
    cout << knapsack_DP(val,wght,3,50) << endl;
}