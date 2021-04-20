#include <iostream>
#include "Node.cpp"
using namespace std;

bool hasLoop(Node *head) {
    if(head == NULL || head->next == NULL) {
        return false;
    }

    Node *fast = head;
    Node *slow = head;

    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) {
            return true;
        }
    }

    return false;
}

Node *startOfLoop(Node *head) {
    Node *fast = head;
    Node *slow = head;

    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) {
            break;
        }
    }

    if(slow!=fast) return NULL;

    slow = head;
    while(slow!=fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

Node *breakLoop(Node *head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node *fast = head;
    Node *slow = head;

    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) {
            slow = head;
            break;
        }
    }

    while (fast->next) {
        if(fast->next = slow) {
            fast->next = NULL;
        }
        fast = fast->next;
        slow = slow->next;
    }

    return head;
}

int main() {
    Node n1(20);
    Node n2(30);
    Node n3(40);
    Node n4(50);
    Node n5(60);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;    
    n5.next = &n2;

    if(hasLoop(&n1)) {
        cout << startOfLoop(&n1) << endl;
    } else {
        return false;
    }

    cout << &n2 << endl; 

}