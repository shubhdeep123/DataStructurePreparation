#include <iostream>
#include "Node.cpp"
using namespace std;

Node *moveLastToFirst(Node *head) {
    if(head==NULL || head->next==NULL) {
        return head;
    }

    Node *tail = head;
    while (tail->next->next != NULL) {
        tail = tail->next;
    }
    Node *newHead = tail->next;
    tail->next = NULL;
    newHead->next = head;

    return newHead; 
}

int main() {
    Node *head = takeInput();
    head = moveLastToFirst(head);
    print(head); 
}
