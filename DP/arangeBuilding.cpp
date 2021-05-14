#include <iostream>
#include<math.h>
using namespace std;

int arrangeBuilding(int n) {
    int *dpB = new int[n + 1];
    int *dpS = new int[n + 1];

    dpB[1] = 1;
    dpS[1] = 1;
    for (int i = 2; i < n+1; i++) {
        dpS[i] = dpB[i - 1] + dpS[i - 1];
        dpB[i] = dpS[i - 1];
    }

    int ans = dpB[n] + dpS[n];

    delete[] dpB, dpS;
    return pow(ans, 2);
}

int arrangeBuildingWithoutArray(int n) {
    int ob = 1;
    int os = 1;

    for (int i = 2; i <= n;i++) {
        int nb = os;
        int ns = os + ob;

        ob = nb;
        os = ns;
    }

    int ans = ob + os;
    ans *= ans;

    return ans;
}

int main () {
    int n;
    cin >> n;

    cout << arrangeBuildingWithoutArray(n) << endl;
}