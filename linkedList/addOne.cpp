#include <iostream>
#include "Node.cpp"
using namespace std;


int fetchNum(Node *head) {
    if(head == NULL) {
        return 0;
    }

    if(head->next == NULL) {
        return head->data;
    }

    int result = 0;
    Node *temp = head;
    while(temp!=NULL) {
        result = result*10 + temp->data;
        temp=temp->next;
    }
    return result;
}

Node *addTwo(Node *head1, Node *head2) {
    int num1,num2;
    num1=fetchNum(head1);
    num2=fetchNum(head2);
    int ans = num1 + num2;

    Node *head = NULL;
    while(ans) {
        int rem = ans%10;
        ans = ans/10;
        Node  *newNode = new Node(rem);
        newNode->next = head;
        head = newNode;
    }

    return head;
}

int addOne(Node *head) {
    if (head == NULL) {
        return 0;
    }

    if (head->next == NULL) {
        return head->data + 1;
    }

    Node *temp = head;
    int result = 0;
    while(temp!=NULL) {
        result = result*10 + temp->data;
        temp=temp->next;
    }

    return result+1;
}

int main() {
    Node *head1 = takeInput();
    Node *head2 = takeInput();
    Node *head = addTwo(head1,head2);
    print(head);
}