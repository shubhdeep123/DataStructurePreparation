#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int negEle = 0;
    for (int i=0; i<n; i++) {
        if (arr[i] < 0) {
            swap(arr[i],arr[negEle]);
            negEle++;
        }
    }

    sort(arr,arr + negEle);

    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;

}