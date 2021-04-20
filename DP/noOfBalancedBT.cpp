#include<iostream>
using namespace std;

int noOfBalancedBT(int h) {
    if (h==0 || h==1) {
        return h;
    }

    if (h == 2) {
        return 3;
    }

    int x = noOfBalancedBT(h-1);
    int y = noOfBalancedBT(h-2);

    int ans = x*x + 2*x*y;
    return ans;
}

int noOfBalancedBT_Mem(int h, int *arr) {
    // BASE CASE
    if (h==0 || h==1) {
        return h;
    }

    if (h == 2) {
        return 3;
    }

    // If answer exits return it
    if (arr[h] != -1) {
        return arr[h];
    }

    // recursive calls
    int x = noOfBalancedBT(h-1);
    int y = noOfBalancedBT(h-2);

    arr[h] = x*x + 2*x*y;
    return arr[h];
}

int noOfBalancedBT_DP(int h) {
    int *arr = new int[h+1];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 3;

    for (int i=3; i<=h; i++) {
        int x = arr[i-1];
        int y = arr[i-2];
        arr[i] = x*x + 2*x*y;
    }

    return arr[h];
}

int main() {
    int h;
    cin >> h;
    // BRUTE FORCE
    cout << noOfBalancedBT(h) << endl;
    // MEMOIZATION
    int *arr = new int[h+1];
    for (int i=0; i<=h; i++) {
        arr[i] = -1;
    }
    cout << noOfBalancedBT_Mem(h,arr) << endl;
    // Dynamic Programming
    cout << noOfBalancedBT_DP(h) << endl;
}