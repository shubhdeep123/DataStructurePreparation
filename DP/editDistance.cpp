#include<iostream>
#include<string>
using namespace std;

int editDistance(string s, string t) {
    int m = s.size();
    int n = t.size();

    if (m==0 && n==0) {
        return 0;
    }

    if (m==0 && n!=0) {
        return n;
    }

    if (m!=0 && n==0) {
        return m;
    }

    if (s[0]==t[0]) {
        return editDistance(s.substr(1),t.substr(1));
    } else {
        int Insert = editDistance(s.substr(1),t);
        int Delete = editDistance(s,t.substr(1));
        int replace = editDistance(s.substr(1),t.substr(1));

        int ans = 1 + min(replace , min(Insert,Delete));
        return ans;
    }
}

int editDistance_Mem(string s, string t, int **output) {
    int m = s.size();
    int n = t.size();
    // BASE CASE
    if (m==0 && n==0) {
        return 0;
    }

    if (m==0 && n!=0) {
        return n;
    }

    if (m!=0 && n==0) {
        return m;
    }

    // Check if answer exits
    if (output[m][n] != -1) {
        return output[m][n];
    }

    // Recursive calls
    if (s[0]==t[0]) {
        output[m][n] = editDistance(s.substr(1),t.substr(1));
    } else {
        int Insert = editDistance(s.substr(1),t);
        int Delete = editDistance(s,t.substr(1));
        int replace = editDistance(s.substr(1),t.substr(1));

        output[m][n] = 1 + min(replace , min(Insert,Delete));
    }

    return output[m][n];
}

int editDistance_DP(string s, string t) {
    int m = s.size();
    int n = t.size();

    int **output = new int*[m+1];
    for (int i=0; i<=m; i++) {
        output[i] = new int[n+1];
    }

    output[0][0] = 0;

    // fill first row
    for (int i=1; i<=n; i++) {
        output[0][i] = i;
    }

    // fill first col
    for (int i=1; i<=m; i++) {
        output[i][0] = i;
    }

    // fill remaining rows and col
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if (s[m-i]==t[n-j]) {
                output[i][j] = output[i-1][j-1];
            } else {
                int Insert = output[i-1][j];
                int Delete = output[i][j-1];
                int replace = output[i-1][j-1];

                output[i][j] = 1 + min(replace , min(Insert,Delete));
            }
        }
    }

    return output[m][n];

}

int main () {
    string s,t;
    cin >> s >> t;
    int m = s.size();
    int n = t.size();
    // BRUTE FORCE
    cout << editDistance(s,t) << endl;
    // MEMOIZATION
    int **arr = new int*[m+1];
    for (int i=0; i<=m; i++) {
        arr[i] = new int[n+1];
        for (int j=0; j<=n; j++) {
            arr[i][j] = -1;
        }
    }
    cout << editDistance_Mem(s,t,arr) << endl;
    // DYNAMIC PROGRAMMING
    cout << editDistance_DP(s,t) << endl;
}