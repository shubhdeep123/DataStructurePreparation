#include<iostream>
#include <climits>
using namespace std;

int main(){
    int size;
    cin >> size;

    int *arr = new int[size];
    for (int i=0; i<size; i++) {
        cin >> arr[i];
    }
    /* BRUTE FORCE APPROACH
    int sum = INT_MIN;
    for (int i=0; i<size; i++) {
        for (int j=i; j<size; j++) {
            int temp = 0;
            for (int k=i; k<=j; k++) {
                temp = temp + arr[k];
            }
            sum = max(sum,temp);
        }
    }
    delete [] arr;
    cout << sum << endl;
    */

   /*CUMULATIVE SUM APPROACH
    int *currSum = new int[size+1];
    currSum[0] = 0;

    for (int i=1; i<=size; i++) {
        currSum[i] = currSum[i-1] + arr[i-1];
    }

    int maxSum = INT_MIN;
    for (int i=1; i<=size; i++) {
        int sum = 0; 
        for (int j=0; j<i; j++) {
            sum = currSum[i] - currSum[j];
            maxSum = max(sum,maxSum);
        }
    }

    delete [] currSum;
    delete [] arr;
    cout << maxSum << endl;
    */

   /* KADANE'S APPROACH*/
   int maxSum = INT_MIN;
   int currentSum = 0;

   for (int i=0; i<size; i++) {
       currentSum += arr[i];
       if (currentSum < 0) {
           currentSum = 0;
       }
       maxSum = max(maxSum,currentSum);
   }

    delete [] arr;
    cout << maxSum << endl;
   
}