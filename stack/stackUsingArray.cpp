#include<iostream>
#include <climits>
using namespace std;

class stackUsingArray {
    int *data;
    int nextIndex;
    int capacity;

    public:
    stackUsingArray(int totalsize) {
        data = new int[totalsize];
        nextIndex = 0;
        this->capacity = totalsize;
    }

    int size() {
        return nextIndex;
    }

    bool isEmpty() {
        return nextIndex == 0;
    }

    void push(int value) {
        if (nextIndex==capacity) {
            cout << "Stack is full" << endl;
            return;
        }
        
        data[nextIndex] = value;
        nextIndex++; 
    }

    int pop() {
        if(isEmpty()) {
            cout << "Stack is Empty" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    } 

    int top() {
         if(isEmpty()) {
            cout << "Stack is Empty" << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};