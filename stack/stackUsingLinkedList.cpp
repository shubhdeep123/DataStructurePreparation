#include <iostream>
using namespace std;

template <typename T>
class Node {
    public:
    T data;
    Node<T> *next;

    Node(T data) {
        this->data = data;
        next = NULL;
    }
};

template <typename T>

class Stack {
    Node<T> *head;
    int size;

    public:

    Stack() {
        head=NULL;
        size=0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size==0;
    }

    void push(T value) {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
        size++;
    }

    T pop() {
        if(head==NULL) {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        Node<T> *temp = head;
        T ans = temp->data;
        head = head->next;
        delete newNode;
        size--;
        return ans;
        
    }

    T top() {
        return head->data;
    }

};

int main() {
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.getSize() << endl;
    cout << s.top() << endl;
    cout << s.isEmpty() << endl;
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
}