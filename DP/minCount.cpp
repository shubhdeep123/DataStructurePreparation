#include<iostream>
#include<math.h>
using namespace std;

int minCount (int n) {
    // if n is a perfect square then minCount will be 1;
    if (sqrt(n) - floor(sqrt(n))==0) {
        return 1;
    }
    
    if (n<=3) {
        return n;
    }

    // get minCount rest of the table using recursive formula
    // maximum squares required(1*1 + 1*1  + 1*1 +...... )
    int ans = n;
    for (int i=1; i*i<=n; i++) {
        ans = min(ans,1 + minCount(n-(i*i)));
    }

    return ans;
} 

int minCount_Mem (int n, int *arr) {
    // BASE CASE
    // if n is a perfect square then minCount will be 1;
    if (sqrt(n) - floor(sqrt(n))==0) {
        return 1;
    }
    
    if (n<=3) {
        return n;
    }

    // check if Ans exists
    if (arr[n] != -1) {
        return arr[n];
    }

    // recusive Calls
    int ans = n;
    for (int i=1; i*i<=n; i++) {
        arr[n] = ans = min(ans,1+minCount_Mem(n-i*i,arr));
    }

    return arr[n];
}

int minCount_DP(int n) {
    if (sqrt(n) - floor(sqrt(n)) == 0) {
        return 1;
    }

    int *dp = new int[n+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for (int i=4; i<=n; i++) {
        dp[i] = i;

        for (int x=1; x <= ceil(sqrt(i)); x++) {
            int temp = x*x;
            if (temp > i)
                break;
            else 
                dp[i] = min(dp[i],1+dp[i-temp]);
        }
    }

    return dp[n];
}

int main () {
    cout << ceil(sqrt(4)) << endl;
    int n;
    cin >> n;
    // BRUTE FORCE
    cout << minCount(n) << endl;
    // MEMOIZATION
    int *arr = new int[n+1];
    for (int i=0; i<=n; i++) {
        arr[i] = -1;
    }
    cout << minCount_Mem(n,arr) << endl;
    // DYNAMIC PROGRAMMING
    cout << minCount_DP(n) << endl;
}