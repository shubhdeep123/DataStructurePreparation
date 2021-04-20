#include <iostream>
#include <string.h>
using namespace std;

class Student {
    int age;
    char *name;

    public:
    
    Student(int age, char *name) {
        this -> age = age;
        // Shallow Copy;
        // this -> name = name;
        
        // Deep Copy
        this -> name = new char[strlen(name)+1];
        strcpy(this -> name,name);
    }

    void print() {
        cout << age << " " << name << endl;
    }
};

int main() {
    char name[] = "abcd";
    Student s1(20,name);
    Student s2 = s1;
    s1.print();
    name[3] = 'e';
    s2.print();
}