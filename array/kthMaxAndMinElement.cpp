#include<bits/stdc++.h>
#include<climits>
using namespace std;

int main () {
    int n,kMax,kMin;
    cout << "Enter N, kMax and kMin: " << endl;
    cin >> n >> kMax >> kMin;

    cout << "Enter Array: " << endl;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr,arr+n);

    cout << "kMax: " << arr[n-kMax] << " kMin: " << arr[kMin-1] << endl;

    return 0;

}