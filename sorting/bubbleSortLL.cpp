#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

int length (Node *head) {
    Node *temp = head;
    int count = 0;
    while(temp!= NULL) {
        temp=temp->next;
        count++;
    }

    return count;
}

Node* takeInput() {
    int data;
    cin >> data;
    Node *head = NULL;
    while(data != -1) {
        Node *newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp -> next != NULL) {
                temp = temp -> next; 
            }
            temp -> next = newNode;
        } 
        cin >> data;
    }
    return head;
}

void print (Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

Node *bubbleSort(Node *head) {
    if(head==NULL || head->next==NULL) {
        return head;
    }

    for (int i=0; i<length(head); i++) {
        Node *prev = NULL;
        Node *curr = head;

        while (curr->next != NULL) {
            if (curr->data > curr->next->data) {
                if (prev==NULL) {
                    head= curr->next;
                    curr->next=head->next;
                    head->next=curr;
                    prev=head;
                } else {
                    // swapping using those 4 steps
                    Node* t=curr->next->next;
                    curr->next->next= curr;
                    prev->next=curr->next;
                    curr->next=t;
                    prev=prev->next;
                }
            } else {
                prev=curr;
                curr=curr->next;
            }
        }
    }

    return head;
}

int main() {
    Node *head = takeInput();
    head = bubbleSort(head);
    print(head);
}