#include <iostream>
using namespace std;
#include <stack>
#include <string>

bool ArePair (char opening, char closing) {
    if (opening=='{' && closing=='}') return true;
    else if (opening=='(' && closing==')') return true;
    else if (opening=='[' && closing==']') return true;
    return false;
}

bool AreParanthesisBalanced(string str) {
    stack<char> s; 

    for (int i=0; i<str.length(); i++) {
        if(str[i] == '{' || str[i] == '(' || str[i] == '[') {
            s.push(str[i]);
        } else if (str[i] == '}' || str[i] == ')' || str[i] == ']') {
            if(s.empty() || !ArePair(s.top(),str[i])) {
                return false;
            } else {
                s.pop();
            }
        }
    }

    return s.empty() ? true:false;
}

int main () {
    string str;
    cin >> str;

    cout << AreParanthesisBalanced(str) << endl;
}