#include<iostream>
#include<stack>
#include<string>
using namespace std;

int countBracketReversals(string input) {
	stack<char> left, right;
    for (int i=0; i<input.length(); i++) {
        if(input[i] == '{') {
            right.push(input[i]);
        } else if (input[i]=='}') {
            left.push(input[i]);
        }
    }

    int leftSize = left.size();
    int rightSize = right.size();
    int count = 0;

    if(leftSize==rightSize) {
        return rightSize + 1;
    } else if (leftSize > rightSize) {
        count = leftSize - rightSize;
        if (count%2==0) {
            return (rightSize + (count/2));
        } else {
            return -1;
        }   
    } else if (rightSize > leftSize) {
        count = rightSize - leftSize;
        if (count%2==0) {
            return (leftSize + (count/2));
        } else {
            return -1;
        }
    } else {
        return -1;
    }
}

int main() {
    string str;
    cin >> str;
    cout << countBracketReversals(str) << endl;
}