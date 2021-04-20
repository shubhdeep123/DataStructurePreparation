#include <iostream>
using namespace std;

int highestDivisor(int n) {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int divisor = 0;
    int temp = 0;
    for (int i=0; i<10; i++) {
        if (n%arr[i] == 0) {
            temp = arr[i];
        }
        divisor = max(temp,divisor);
    }

    return divisor;
}

int main () {
    cout << highestDivisor(68) << endl;
    return 0;
}