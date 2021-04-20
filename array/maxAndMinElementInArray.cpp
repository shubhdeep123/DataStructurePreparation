#include<iostream>
#include<climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int min = INT_MAX;
    int max = INT_MIN;

    for (int i=0; i<n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        } else if (arr[i] > max) {
            max = arr[i];
        }
    }

    cout << "Max: " << max << " Min: " << min << endl;

    return 0;
}