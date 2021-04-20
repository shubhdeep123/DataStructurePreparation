#include<iostream>
using namespace std;

class ComplexNumber {
    private:
    int real_number;
    int imaginary_number;

    public:
    ComplexNumber() {
        // constructor
    }

    // constructor made by me
    ComplexNumber(int real_number, int imaginary_number) {
        this -> real_number = real_number;
        this -> imaginary_number = imaginary_number;
    }

    ComplexNumber add(ComplexNumber const &c) {
        ComplexNumber cNew;
        cNew.real_number = this -> real_number + c.real_number;
        cNew.imaginary_number = this -> imaginary_number + c.imaginary_number; 

        return cNew;
    }

    ComplexNumber subtract(ComplexNumber const &c) {
        ComplexNumber cNew;
        cNew.real_number = this -> real_number - c.real_number;
        cNew.imaginary_number = this -> imaginary_number - c.imaginary_number;

        return cNew; 
    }

    ComplexNumber multiply(ComplexNumber const &c) {
        ComplexNumber cNew;
        cNew.real_number = (this -> real_number)*c.real_number + (this -> imaginary_number)*c.imaginary_number*(-1);
        cNew.imaginary_number = (this -> imaginary_number)*c.real_number + (this -> real_number)*c.imaginary_number;

        return cNew;
    }

    ComplexNumber divide(ComplexNumber const &c) {
        ComplexNumber cPos, cNeg, cNew;
        cPos = c;
        cNeg = c;
        cNeg.imaginary_number = - (c.imaginary_number);
        ComplexNumber cNum = (*this).multiply(cNeg);
        ComplexNumber cDeno = cPos.multiply(cNeg);
        cNew.real_number = cNum.real_number/cDeno.real_number;
        cNew.imaginary_number = cNum.imaginary_number/cDeno.real_number;

        return cNew;
    }

    // Operator Overloading

    ComplexNumber operator+(ComplexNumber const &c) {
        ComplexNumber cNew;
        cNew.real_number = this -> real_number + c.real_number;
        cNew.imaginary_number = this -> imaginary_number + c.imaginary_number; 

        return cNew;
    }

    ComplexNumber operator-(ComplexNumber const &c) {
        ComplexNumber cNew;
        cNew.real_number = this -> real_number - c.real_number;
        cNew.imaginary_number = this -> imaginary_number - c.imaginary_number;

        return cNew; 
    }

    ComplexNumber operator*(ComplexNumber const &c) {
        ComplexNumber cNew;
        cNew.real_number = (this -> real_number)*c.real_number + (this -> imaginary_number)*c.imaginary_number*(-1);
        cNew.imaginary_number = (this -> imaginary_number)*c.real_number + (this -> real_number)*c.imaginary_number;

        return cNew;
    }

    ComplexNumber operator/(ComplexNumber const &c) {
        ComplexNumber cPos, cNeg, cNew;
        cPos = c;
        cNeg = c;
        cNeg.imaginary_number = - (c.imaginary_number);
        ComplexNumber cNum = (*this).multiply(cNeg);
        ComplexNumber cDeno = cPos.multiply(cNeg);
        cNew.real_number = cNum.real_number/cDeno.real_number;
        cNew.imaginary_number = cNum.imaginary_number/cDeno.real_number;

        return cNew;
    }
    
    void print() {
        cout << this -> real_number << " + " << this -> imaginary_number << "i" << endl;
    }
};

int main () {
    ComplexNumber c1(3,6);
    ComplexNumber c2(1,1);

    ComplexNumber c3;

    c3 = c1 * c2;
    c3.print();
}