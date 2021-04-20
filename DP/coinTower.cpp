#include <iostream>
using namespace std;

string findTheWinner(int n, int x, int y) {
    int *dp = new int[n+1];
    dp[0] = false;
    dp[1] = true;

    for (int i=2; i<=n; i++) {
        if (i-1 >= 0 && !dp[i-1]) {
            dp[i] = true;
        } else if (i-x >= 0 && !dp[i-x]) {
            dp[i] = true;
        } else if (i-y >=0 && !dp[i-y]) {
            dp[i] = true;
        } else {
            dp[i] = false;
        }
    }

    if (dp[n]) {
        return "Beerus";
    } else {
        return "Whis";
    }
}

int main() {
    cout << findTheWinner(10,2,4) << endl;
}