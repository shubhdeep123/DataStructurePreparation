#include<iostream>
#include<climits>
using namespace std;

int minCostPath_helper(int **arr, int m, int n, int i, int j) {
    // BASE CASE
    if (i==m-1 && j==n-1) {
        return arr[i][j];
    }

    if (i>=m || j>=n) {
        return INT_MAX;
    }

    // Recursive Call
    int x = minCostPath_helper(arr,m,n,i,j+1);
    int y = minCostPath_helper(arr,m,n,i+1,j+1);
    int z = minCostPath_helper(arr,m,n,i+1,j);

    // Small Calculation
    int ans = arr[i][j] + min(x,min(y,z));

    return ans; 
}

int minCostPath(int **arr, int m, int n) {
    return minCostPath_helper(arr,m,n,0,0);
}

int minCostPath_Mem_helper(int **arr, int m, int n, int i, int j, int **output) {
    // Base Case
    if (i==m-1 && j==n-1) {
        return arr[i][j];
    }

    if (i>=m || j>=n) {
        return INT_MAX;
    }

    // Check if answer exists
    if (output[i][j] != -1) {
        return output[i][j];
    }

    // recursive Calls
    int x = minCostPath_Mem_helper(arr,m,n,i+1,j,output);
    int y = minCostPath_Mem_helper(arr,m,n,i+1,j+1,output);
    int z = minCostPath_Mem_helper(arr,m,n,i,j+1,output);

    // small calculation
    int ans = arr[i][j] + min(x,min(y,z));

    // save answer
    output[i][j] = ans;

    return ans;
}

int minCostPath_Mem(int **arr, int m, int n) {
    int **output = new int*[m];
    for (int i=0; i<m; i++) {
        output[i] = new int[n];
        for (int j=0; j<n; j++) {
            output[i][j]=-1;
        }
    }

    return minCostPath_Mem_helper(arr,m,n,0,0,output);
}

int minCostPath_DP(int **arr, int m, int n) {
    int **output = new int*[m];
    for (int i=0; i<m; i++) {
        output[i] = new int[n];
    }

    // Fill Last Cell
    output[m-1][n-1] = arr[m-1][n-1];

    // last row right to left
    for (int i=n-2; i>=0; i--) {
        output[m-1][i] = arr[m-1][i] + output[m-1][i+1];
    }

    // last col
    for (int i=m-2; i>=0; i--) {
        output[i][n-1] = arr[i][n-1] + output[i+1][n-1];
    }

    // Fill remaining cell
    for (int i=m-2; i>=0; i--) {
        for (int j=n-2; j>=0; j--) {
            output[i][j] = arr[i][j] + min (output[i+1][j+1], min (output[i+1][j],output[i][j+1]));
        }
    }

    return output[0][0];
}

int main () {
    int m,n;
    cin >> m >> n; 
    int **arr = new int*[m];
    for (int i=0; i<m; i++) {
        arr[i] = new int[n];
        for (int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }
    // BRUTE FORCE
    cout << minCostPath(arr,m,n) << endl;

    // MEMOIZATION
    cout << minCostPath_Mem(arr,m,n) << endl;

    // DYNAMIC PROGRAMMING
    cout << minCostPath_DP(arr,m,n) << endl;

}

// 3 3
// 1 10 5
// 2 4 6
// 7 3 1

// 3 3
// 8 10 3
// 2 0 4
// 1 6 5