#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node (int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

Node* takeInput() {
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1 ) {
        Node *newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            // Node *temp = head;
            // while (temp -> next != NULL) {
            //     temp = temp -> next;
            // }
            // temp -> next = newNode;
            //    OR
            tail -> next = newNode;
            tail = newNode;
        }

        cin >> data;
    }
    return head;
}

Node *deleteNode(Node *head, int pos) {
    if (head == NULL) {
        return head;
    } 

    if (pos == 0) {
        return head -> next;
    }

    Node *temp = head;
    int count=0;

    while (temp != NULL && count < pos -1) {
        temp = temp -> next;
        count++;
    }

    if (temp == NULL || temp->next == NULL) {
        return head;
    }

    temp -> next = temp -> next -> next;

    return head;
}

int findNode(Node *head, int n) {
    Node *temp = head;
    int count = 0;
    while (temp != NULL) {
        if (temp->data == n) {
            return count;
        }
        temp = temp -> next;
        count++;
    }

    return -1;
}

int length(Node *head) {
    if(head == NULL) {
        return 0;
    }
    
    Node *temp = head;
    
    if (temp != NULL) {
        int ans = length(temp -> next);
        return ans + 1;
    }
}

void print(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {
    Node *head = takeInput();
    print(head);
    int n;
    cin >> n;
    cout << findNode(head, n) << endl;
}