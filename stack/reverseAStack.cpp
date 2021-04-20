#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int ele) {
    
    if (s.empty()) {
        s.push(ele);
        return;
    }

    int topEle = s.top();
    s.pop();
    insertAtBottom(s,ele);

    s.push(topEle);
}

void reverseStack(stack<int> &s) {
    if(s.empty()) {
        return;
    }
    
    int ele = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s,ele);

}

int main () {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    reverseStack(s);
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
}