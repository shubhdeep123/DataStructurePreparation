#include <iostream>
using namespace std;

template <typename T>
class Node {
    public:
    T data;
    Node<T> *next;

    Node(T value) {
        data = value;
        next = NULL;
    } 
};

template <typename T>
class stack {
    Node<T> *head;
    int size;
    
    public:
    stack () {
        head = NULL;
        size = 0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size==0;
    }

    void push(T element) {
        Node<T> *newNode = new Node<T>(element);
        if (head==NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    T pop() {
        if (head==NULL) {
            return 0;
        }
        Node<T> *temp = head;
        T ans = temp->data;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }

    T top() {
        if (head==NULL) {
            return 0;
        }
        return head->data;
    }
};

int main() {
    stack<int> s;
    s.push(10);
    s.push(100);
    s.push(1000);
    s.push(10000);
    s.push(100000);
    s.push(1000000);

    cout << s.getSize() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.isEmpty() << endl; 
}