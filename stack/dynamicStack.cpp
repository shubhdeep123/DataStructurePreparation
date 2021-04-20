#include<iostream>
#include <climits>
using namespace std;

class stackUsingArray {
    int *data;
    int nextIndex;
    int capacity;

    public:
    stackUsingArray() {
        capacity=4;
        data = new int[capacity];
        nextIndex = 0;
    }

    int size() {
        return nextIndex;
    }

    bool isEmpty() {
        return nextIndex == 0;
    }

    void push(int value) {
        if (nextIndex==capacity) {
            int *newData = new int[2*capacity];
            for(int i=0; i<capacity; i++) {
                newData[i] = data[i];
            }
            delete [] data;
            data = newData;
            capacity *= 2;
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