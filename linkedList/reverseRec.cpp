#include <iostream>
#include "Node.cpp"
using namespace std;

class Pair {
    public:
    Node *head;
    Node *tail;
};

Pair reverseHeadAndTail(Node *head) {
    if (head == NULL || head->next == NULL) {
        Pair p;
        p.head = head;
        p.tail = head;
        return p;
    }

    Pair reversePair;
    reversePair = reverseHeadAndTail(head->next);
    Node *temp = reversePair.head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;

    Node *tail = reversePair.head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    Pair p;
    p.head = reversePair.head;
    p.tail = tail;
    return p;
}

Node *reverseRec(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node *newHead = reverseRec(head->next);
    Node *temp = newHead;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;

    return newHead;
}

Node *reverseIterative(Node *head) {
    if(head==NULL || head->next == NULL) {
        return head;
    }

    Node *prev = NULL;
    Node *curr = head;
    Node *next;

    while (curr != NULL) {
        next = curr->next;
        curr->next=prev;
        prev=curr;
        curr=next; 
    }

    return prev;
}

Node *kReverse(Node *head, int k) {
    if(head==NULL || head->next == NULL) {
        return head;
    }
    // code to find the first kth tail
    Node *tail = head;
    int count = 1;
    while (count!=k) {
        tail = tail->next;
        count++;
    }
    Node *head2 = kReverse(tail->next,k);
    tail->next = NULL;
    
    Pair p;
    p = reverseHeadAndTail(head);
    p.tail->next = head2;

    return p.head; 
}

int main() {
    Node *head = takeInput();
    int k;
    cin >> k;
    head = kReverse(head,k);
    print(head);
}
