#include<iostream>
#include "Node.cpp"
using namespace std;

void print (Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main () {
    // statically
    Node n1(10);
    Node n2(20);

    Node *head = &n1;
    n1.next = &n2;

    cout << n1.data << " " << n2.data << endl;

    Node *n3 = new Node(30);
    Node *n4 = new Node(40);
    n2.next = n3;
    n3 -> next = n4; 

    print(head);
    

}