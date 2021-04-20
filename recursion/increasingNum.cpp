#include <iostream>
using namespace std;

// increasing order
int incNumber (int n) {
    if (n==0) {
        cout << n << " ";
        return 0;
    }

    incNumber(n-1);
    cout << n << " ";
    return 0;
}

// decreasing order
int decNumber (int n) {
    if (n==0) {
        cout << n << " ";
        return 0;
    }

    cout << n << " ";
    decNumber(n-1);
    return 0;
}

int main() {
    int n = 10;
    incNumber(n);
    cout << endl;
    decNumber(n);
    return 0;
}