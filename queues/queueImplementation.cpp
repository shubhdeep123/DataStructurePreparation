#include <iostream>
using namespace std;

template <typename T>
class Node {
    public:
    T data;
    Node<T> *next;

    Node (T value) {
        data = value;
        next = NULL;
    }
};

template <typename T>
class queue {
    Node<T> *head;
    Node<T> *tail;
    int size;

    public:
    queue() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size==0;
    }

    void enqueue(T element) {
        Node<T> *newNode = new Node<T>(element);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    T dequeue() {
        if (head == NULL) {
            return 0;
        }
        Node<T> *temp = head;
        T ans = temp->data;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }

    T front() {
        if (head==NULL) {
            return 0;
        }
        return head->data;
    }
};

int main () {
    queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << q.getSize() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.front() << endl;
    cout << q.isEmpty() << endl;
}