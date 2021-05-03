#include<iostream>
using namespace std;

// Array preprocessing 
// Only one stock can be bought
// and you cannot sell before buying
int buyAndSellStock(int *arr, int n) {
    int minSoFar = arr[0];
    int maxProfit = 0;
    for (int i=0; i<n; i++) {
        minSoFar = min(arr[i],minSoFar);
        int profit = arr[i] - minSoFar;
        maxProfit = max(profit,maxProfit);
    }

    return maxProfit;
}

// buy and sell as many times you want but you need to have only one stock at a time, 
// it is to maximise the profit
int buyAndSellStockMaxProfit(int *arr, int n) {
    int profit =0;
    for (int i=1; i<n; i++) {
        if (arr[i] > arr[i-1]) {
            profit += (arr[i] - arr[i-1]);
        }
    }

    return profit;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << buyAndSellStock(arr,n) << endl;
    cout << buyAndSellStockMaxProfit(arr,n) << endl;
    
    return 0;
}