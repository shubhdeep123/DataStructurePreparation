#include <iostream>
#include <stack>
using namespace std;

void reverseSentence (string exp) {
    stack<string> s;
    for (int i=0; i<exp.length(); i++) {
        string word="";
        while(exp[i]!=' ' && i<exp.length()) {
            word += exp[i];
            i++;
        }
        s.push(word);
    }

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    } 
    cout << endl;
}

int main () {
    string s = "Hey, how are you doing?";
    reverseSentence(s);
}