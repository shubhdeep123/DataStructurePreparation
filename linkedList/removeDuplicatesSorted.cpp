#include <iostream>
#include "Node.cpp"
using namespace std;

Node *removeDuplicatesSorted(Node *head) {
    if (head==NULL || head->next == NULL) {
        return head;
    }

    Node *t1 = head;
    Node *t2 = head->next;
     while (t2 != NULL) {
        if (t1->data == t2->data) {
            Node *temp = t2;
            t2 = t2->next;
            delete temp;
        } else {
            t1->next = t2;
            t1=t2;
            t2 = t2->next;
        }
    }

    return head;
}

int main () {
    Node *head = takeInput();
    head = removeDuplicatesSorted(head);
    print(head);
}