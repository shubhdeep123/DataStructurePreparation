#include<iostream>
using namespace std;

int unboundedKnapsack(int n, int *value, int *wt, int cap) {
    int *dp = new int[cap + 1];
    dp[0] = 0;

    for (int bagc = 0; bagc <= cap; bagc++) {
        int max = dp[bagc];
        for (int i = 0; i < n; i++) {
            if (wt[i] <= bagc)
            {   
                int rbagc = bagc - wt[i];
                int rbagv = dp[rbagc];
                int tbagc = rbagv + value[i];

                if (tbagc > max) {
                    max = tbagc;
                }
            }
        }
        dp[bagc] = max;
    }

    return dp[cap];
}

int main() {
    int n,cap;
    cin >> n;
    int *value = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }
    int *wt = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }
    cin >> cap;

    cout << unboundedKnapsack(n, value, wt, cap) << endl;
}