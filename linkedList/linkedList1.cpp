#include <iostream>
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
    // Statically Created LinkedList
    // Node n1(1);
    // Node n2(2);
    // Node n3(3);
    // Node n4(4);
    // Node n5(5);

    // Node *head = &n1;
    // n1.next = &n2;
    // n2.next = &n3;
    // n3.next = &n4;
    // n4.next = &n5;

    // print(head);
    // print(head);

    // Dynamically Created LinkedList
    Node *n1 = new Node(10);
    Node *n2 = new Node(20);
    Node *n3 = new Node(30);
    Node *n4 = new Node(40);
    Node *n5 = new Node(50);

    Node *head = n1;
    n1 -> next = n2;
    n2 -> next = n3;
    n3 -> next = n4;
    n4 -> next = n5;

    print(head);
    print(head);

    

}