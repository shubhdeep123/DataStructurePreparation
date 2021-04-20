#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

bool checkRedundantBrackets(string expression) {
	// Write your code here
    int count=0;
    stack<char> s;
    int i;
    for (i=0; i<expression.length(); i++) {
        count=0;
        if(expression[i]==')') {
            while (s.top() != '(') {
                s.pop();
                count++;
            }
            s.pop();
            if(count<=1) {
                return true;
            }
        }
        s.push(expression[i]);
    }
    return false;
}

int main() {
    string str;
    cin >> str;
    cout << checkRedundantBrackets(str) << endl;
}