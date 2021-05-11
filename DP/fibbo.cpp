#include<iostream>
using namespace std;

int fibbo_mem(int n, int *arr) {
    if (n==0 || n==1) {
        return n;
    }

    if (arr[n] != -1) {
        return arr[n];
    }

    int fibbo1 = fibbo_mem(n - 1, arr);
    int fibbo2 = fibbo_mem(n - 2, arr);
    int fibn = fibbo1 + fibbo2;

    arr[n] = fibn;
    return fibn;
}

int fibbo_dp(int n) {
    int *arr = new int[n + 1];
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i<n+1; i++){
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    
    int ans = arr[n];
    delete[] arr;
    return ans;
}

int main () {
    int n;
    cin >> n;
    int *arr = new int[n+1];
    for (int i = 0; i < n+1; i++) {
        arr[i] = -1;
    }

    cout << fibbo_dp(n) << endl;
}