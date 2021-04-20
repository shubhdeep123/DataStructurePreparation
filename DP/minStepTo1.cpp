#include<iostream>
#include<climits>
using namespace std;

int minStepTo1 (int n) {
    if (n==1) {
        return 0;
    }

    int x = minStepTo1(n-1);
    int y=INT_MAX, z=INT_MAX;
    if (n%2==0) {
        y = minStepTo1(n/2); 
    }
    if (n%3==0) {
        z = minStepTo1(n/3);
    }

    int ans = 1 + min(x,min(y,z));
    return ans;
}

int minStepTo1_Mem(int n, int *ans) {
    // Base case
    if (n==1) {
        return 0;
    }

    // Check if answer exists
    if (ans[n] !=-1) {
        return ans[n];
    }

    // Recursive calls
    int x = minStepTo1_Mem(n-1,ans);
    int y=INT_MAX, z=INT_MAX;
    if (n%2==0) {
        y = minStepTo1_Mem(n/2,ans); 
    }
    if (n%3==0) {
        z = minStepTo1_Mem(n/3,ans);
    }

    ans[n] = 1 + min(x,min(y,z));
    return ans[n];
}

int minStepTo1_DP(int n) {
    int *ans = new int[n+1];

    ans[1] = 0;
    ans[2] = ans[3] = 1;
    int b,c;

    for (int i=2; i<=n; i++) {
        b=c=n;
        if (b%2==0) {
            b = ans[i/2];
        } 
        if (c%3==0) {

            c = ans[i/3];
        }

        ans[i] = 1 + min(ans[i-1],min(b,c));
    }

    return ans[n];
}

int main() {
    int n;
    cin >> n;
    // Brute force
    cout << minStepTo1(n) << endl;
    // Memoization
    int *arr = new int [n+1];
    for (int i=0; i<=n; i++) {
        arr[i] = -1;
    }
    cout << minStepTo1_Mem(n,arr) << endl;
    delete [] arr;
    // Dynamic Programming
    cout << minStepTo1_DP(n) << endl;
}