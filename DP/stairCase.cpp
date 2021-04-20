#include<iostream>
#include<climits>
using namespace std;

int stairCase (int n) {
    if (n==0 || n==1) {
        return 1;
    }

    if (n==2) {
        return 2;
    }

    int x = stairCase(n-1);
    int y = stairCase(n-2); 
    int z = stairCase(n-3);

    int ans = x + y + z;
    return ans;
}

int stairCase_Mem(int n, int *ans) {
    // Base case
    if (n==0 || n==1) {
        return 1;
    }

    if (n==2) {
        return 2;
    }

    // Check if answer exists
    if (ans[n] != -1) {
        return ans[n];
    }

    // Recursive calls
    int x = stairCase_Mem(n-1,ans);
    int y = stairCase_Mem(n-2,ans); 
    int z = stairCase_Mem(n-3,ans);

    ans[n] = x + y + z;
    return ans[n];
    
}

int stairCase_DP(int n) {
    int *ans = new int[n+1];

    ans[0] = ans[1] = 1;
    ans[2] = 2;

    for (int i=3; i<=n; i++) {
        ans[i] = ans[i-1] + ans[i-2] + ans[i-3];
    }

    return ans[n];
}

int main() {
    int n;
    cin >> n;
    // Brute force
    cout << stairCase(n) << endl;
    // Memoization
    int *arr = new int [n+1];
    for (int i=0; i<=n; i++) {
        arr[i] = -1;
    }
    cout << stairCase_Mem(n,arr) << endl;
    delete [] arr;
    // Dynamic Programming
    cout << stairCase_DP(n) << endl;
}