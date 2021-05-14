#include<iostream>
using namespace std;

int countBinaryString (int n) {
    int *dp1 = new int[n + 1];
    int *dp0 = new int[n + 1];

    dp1[1] = dp0[1] = 1;

    for (int i = 2; i < n + 1; i++) {
        dp1[i] = dp1[i - 1] + dp0[i - 1];
        dp0[i] = dp1[i - 1];
    }

    int ans = dp1[n] + dp0[n];
    delete[] dp1, dp0;
    return ans;
}

// without array
int noOfBinaryString(int n) {
    int zeroes = 1;
    int ones = 1;

    for (int i = 2; i <= n; i++) {
        int nZeroes = ones;
        int nOnes = zeroes + ones;

        zeroes = nZeroes;
        ones = nOnes;
    }

    return (zeroes + ones);
}

int main() {
    int n;
    cin >> n;
    cout << countBinaryString(n) << endl;
}