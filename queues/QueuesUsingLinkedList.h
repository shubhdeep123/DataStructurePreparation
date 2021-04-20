template <typename T>
class Node {
    public:
    T data;
    Node<T> *next;

    Node (T data) {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class QueuesUsingLinkedList {
    Node<T> *head;
    Node<T> *tail;
    int size;

    public:
    QueuesUsingLinkedList() {
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
        if (head==NULL) {
            head=newNode;
            tail=newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    T front() {
        if (head==NULL) {
            return 0; 
        }
        return head->data;
    }

    T dequeue() {
        if(isEmpty()) {
            return 0;
        }
        Node<T> *temp = head;
        T ans = temp->data;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }
};