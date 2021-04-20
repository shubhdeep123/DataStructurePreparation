#include <iostream>
using namespace std;

int countWaysToMakeChange(int S[], int m, int n) {
    int *output = new int[n+1];
    // ways to pay 0rs using any coin is 1
    output[0] = 1;

    for (int i=0; i<m; i++) {
        for (int j=S[i]; j<=n; j++) {
            output[j] += output[j-S[i]];
        }
    }

    return output[n];
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int m;
    cin >> m;
    cout << countWaysToMakeChange(arr,n,m) << endl;
}