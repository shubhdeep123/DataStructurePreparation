#include <iostream>
#include "Node.cpp"
using namespace std;

Node *midOfList(Node *head) {
    if(head==NULL || head->next == NULL) {
        return head;
    }

    Node *slow = head;
    Node *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* mergeSortedLL(Node *h1, Node *h2) {
    Node *fHead = NULL;
    Node *fTail = NULL;

    if(h1==NULL) {
        fHead = h2;
        return fHead;
    } else if (h2==NULL) {
        fHead = h1;
        return fHead;
    }

    while (h1 && h2) {
        if(h1->data <= h2->data) {
            if (fHead==NULL) {
                fHead=h1;
                fTail=h1;
                h1 = h1->next;
            } else {
                fTail->next = h1;
                fTail = fTail->next;
                h1 = h1->next;
            }
        } else if(h2->data < h1->data) {
            if (fHead==NULL) {
                fHead=h2;
                fTail=h2;
                h2 = h2->next;
            } else {
                fTail->next = h2;
                fTail = fTail->next;
                h2 = h2->next;
            }
        }
    }

    if (h1!=NULL) {
        fTail->next = h1;
    }

    if (h2!=NULL) {
        fTail->next = h2; 
    }

    return fHead;

}


Node *merge(Node *head) {
    if(head==NULL || head->next==NULL) {
        return head;
    }

    Node *midNode = midOfList(head);

    Node *head2 = merge(midNode->next);
    midNode->next = NULL;
    Node *head1 = merge(head);

    head = mergeSortedLL(head1,head2);

    return head;  
}

int main() {
    Node *head = takeInput();
    head = merge(head);
    print(head);
}