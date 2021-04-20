#include <iostream>
using namespace std;

class Student {
    static int totalStudents;
    public:
    int rollNumber;
    int age;

    Student() {
        totalStudents++;
    }

    int getRollNumber() {
        return rollNumber;
    }


    static int getTotalStudent() {
        return totalStudents;
    }
};

int Student :: totalStudents = 0;

int main() {
    Student s1, s2;
    cout << Student :: getTotalStudent() << endl;
    Student *s3 = new Student;
    cout << Student :: getTotalStudent() << endl;

}