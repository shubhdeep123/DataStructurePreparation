#include <iostream>
using namespace std;

class Student {
    public:
    int age;
    const int rollNumber;

    // Student (int r) {
    //     rollNumber = r;
    // }

    Student(int r) : rollNumber(r) {

    }

    Student(int r, int age) : rollNumber(r), age(age) {

    }
    
};

int main() {
    Student s1(10);
    s1.age = 20;
    Student s2(101,20);
}