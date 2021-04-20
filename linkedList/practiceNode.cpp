#include <iostream>
using namespace std;

class Node {
    public :
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next=NULL; 
    }
};

Node *takeInput() {
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;

    while (data != -1) {
        Node *newNode = new Node(data);
        if(head==NULL) {
            head=newNode;
            tail=newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        cin >> data;
    }
}

int length(Node *head) {
    int count=0;
    Node *temp = head;
    while(temp!=NULL) {
        temp = temp -> next;
        count++;
    }
    return count;
}

Node *deleteNode(Node *head, int pos) {
    if (head == NULL) {
        return head;
    }

    if (pos == 0) {
        return head->next;
    }

    int count=0;
    Node *temp = head;

    while(temp!=NULL || count < pos-1) {
        temp = temp->next;
        count++;
    }

    if(temp==NULL || temp->next==NULL) {
        return head;
    }

    temp -> next = temp->next->next;

    return head;
}