#include <iostream>
#include "Node.cpp"
using namespace std;

Node *reverse(Node* head) {
    Node *prevPtr = NULL;
    Node *currPtr = head;
    Node *nextPtr;

    while (currPtr) {
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;

        prevPtr=currPtr;
        currPtr=nextPtr;
    }
    
    return prevPtr;

}

Node *reverseRecursive(Node *head) {
    if (head==NULL || head->next==NULL) {
        return head;
    }

    Node *newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

int main () {
    Node *head = takeInput();
    head=reverseRecursive(head);
    print(head);
}