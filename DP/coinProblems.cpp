#include<iostream>
using namespace std;

int coinChangeComb(int *coins, int n, int tar) {
    int *dp = new int[tar + 1];
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j < tar + 1; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    return dp[tar];
}

int coinChangePer(int *coins, int n, int tar) {
    int *dp = new int[tar + 1];
    dp[0] = 1;

    for (int i = 0; i < tar + 1;i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                dp[i] += dp[i - coins[j]];
            }
        }
    }

    return dp[tar];
}

// int coinChnageCombination(int *coins, int n, int amt) {
//     int *dp = new int[amt + 1];
//     dp[0] = 1;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = coins[i]; j < amt+1;j++) {
//             dp[j] += dp[j - coins[i]];
//         }
//     }

//     return dp[amt];
// }

// int coinChangePermutation(int *coins, int n, int tar) {
//     int *dp = new int[tar + 1];
//     dp[0] = 1;
//     for (int amt = 1; amt < tar+1; amt++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (coins[j] <= amt) {
//                 int ramt = amt - coins[j];
//                 dp[amt] += dp[ramt];
//             }
//         }
//     }

//     return dp[tar];
// }

int main() {
    int n, amt;
    cin >> n;
    int *coins = new int[n];
    for (int i = 0; i < n;i++) {
        cin >> coins[i];
    }

    cin >> amt;

    cout << coinChangePer(coins, n, amt) << endl;
    cout << coinChangeComb(coins, n, amt) << endl;
}