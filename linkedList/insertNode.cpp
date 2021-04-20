#include <iostream>
#include "Node.cpp"
using namespace std;

Node* insertNode(Node *head, int i, int data) {
    Node *newNode = new Node(data);
    int count = 0;
    Node *temp = head;

    if (i==0) {
        newNode -> next = head;
        head = newNode;
        return head;
    }

    while (temp != NULL && count < i-1) {
        temp = temp -> next;
        count++;
    }
    // way 1:-
    // Node *prevNode = temp -> next;
    // temp -> next = newNode;
    // newNode -> next = prevNode;
    
    // way 2:-
    if (temp != NULL) {
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }

    return head;
}

Node* deleteNode(Node *head, int i) {
    Node *temp = head;
    int count = 0;

    if (i == 0) {
        head = head -> next;
        delete temp;
        return head;
    }

    while (temp != NULL && count < i-1) {
        temp = temp -> next;
        count++;
    }

    if (temp != NULL) {
        Node *a = temp -> next;
        Node *b = a -> next;
        temp -> next = b;
        delete a;
    }

    return head;

}

Node* takeInput_Better() {
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1) {
        Node *newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail -> next = newNode;
            tail = newNode;
        }

        cin >> data;
    }

    return head;
}

void print(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main () {
    Node *head = takeInput_Better();
    int i,data;
    cin >> i ;
    head = deleteNode(head,i);
    print(head);
}