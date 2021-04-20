#include<iostream>
#include "Node.cpp"
using namespace std;

Node *midPoint(Node *head) {
    if (head == NULL) {
        return NULL;
    }

    if (head->next == NULL) {
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

Node *mergeSort(Node *head) {
    if (head==NULL) {
        return NULL;
    }

    if (head->next==NULL) {
        return head;
    }

    Node *headMid = midPoint(head);
    //To break LL in two parts take temp Node having address of headMid and assign it's next as NULL
    Node *temp = headMid;

    headMid = mergeSort(headMid->next);
    temp->next=NULL;
    head = mergeSort(head);

    head = mergeSortedLL(head,headMid);

    return head;
}

int main() {
    Node *head = takeInput();
    head = mergeSort(head);
    print(head);
}