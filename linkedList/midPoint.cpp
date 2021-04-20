#include <iostream>
#include "Node.cpp"
using namespace std;

int midPoint(Node *head) {
    if (head == NULL) {
        return 0;
    }

    if (head->next == NULL) {
        return head->data;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

int main () {
    Node *head = takeInput();
    cout << midPoint(head) << endl;
}