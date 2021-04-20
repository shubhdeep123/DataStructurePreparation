#include <iostream>
#include "Node.cpp"
using namespace std;

Node *intersectionOfSortedLL(Node *head1, Node *head2) {
    if (head1 == NULL && head2 == NULL) {
        return head1;
    }

    if(head1 == NULL && head2 != NULL) {
        return head2;
    }
    
    if(head2 == NULL && head1 != NULL) {
        return head1;
    }

    Node *head = NULL;
    Node *tail = NULL;
    while (head1 != NULL && head2 != NULL) {
        if(head1->data < head2->data) {
            head1=head1->next;
        } else if (head1->data > head2->data) {
            head2=head2->next;
        } else if (head1->data == head2->data) {
            Node *newNode = new Node(head1->data);
            if (head==NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            head1=head1->next;
            head2=head2->next;
        }
    }

    return head;
}

int main() {
    Node *head1 = takeInput();
    Node *head2 = takeInput();
    Node *head = intersectionOfSortedLL(head1,head2);
    print(head);
}