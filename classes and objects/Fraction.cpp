#include <iostream>
using namespace std;

class Fraction {
    private:
    int numerator;
    int denominator;

    public:

    Fraction () {

    }

    Fraction(int numerator, int denominator) {
        this -> numerator = numerator;
        this -> denominator = denominator;
    }

    Fraction (Fraction const &f) {
        this -> numerator = f.numerator;
        this -> denominator = f.denominator;
    }

    void simplify() {
        int gcd = 1;
        int j = min(this -> numerator,this -> denominator);
        for (int i=1; i<=j; i++) {
            if (this -> numerator % i == 0 && this -> denominator % i == 0) {
                gcd = i;
            }
        }

        this -> numerator = this -> numerator / gcd;
        this -> denominator = this -> denominator / gcd; 
    }

    void add(Fraction const &f) {
        int lcm = denominator * f.denominator;
        int x = lcm/denominator;
        int y = lcm/f.denominator;

        numerator = x*numerator + y*(f.numerator);
        denominator = lcm;
        simplify();
    }

    void subtract(Fraction const &f) {
        int lcm = denominator * f.denominator;
        int x = lcm/denominator;
        int y = lcm/f.denominator;

        numerator = x*numerator - y*(f.numerator);
        denominator = lcm;
        simplify();
    }

    void multiply(Fraction const &f) {
        numerator = numerator * f.numerator;
        denominator = denominator * f.denominator;
        simplify();
    }

    void divide(Fraction const &f) {
        numerator = numerator * f.denominator;
        denominator = denominator * f.numerator;
        simplify();
    }

    // OPERATOR OVERLOADING
    Fraction operator+(Fraction const &f) {
        int lcm = denominator * f.denominator;
        int x = lcm/denominator;
        int y = lcm/f.denominator;

        Fraction fNew;
        fNew.numerator = x*numerator + y*(f.numerator);
        fNew.denominator = lcm;
        simplify();

        return fNew;
    }

    Fraction operator-(Fraction const &f) {
        int lcm = denominator * f.denominator;
        int x = lcm/denominator;
        int y = lcm/f.denominator;

        Fraction fNew;
        fNew.numerator = x*numerator - y*(f.numerator);
        fNew.denominator = lcm;
        simplify();

        return fNew;
    }

    Fraction operator*(Fraction const &f) {
        Fraction fNew;
        fNew.numerator = numerator * f.numerator;
        fNew.denominator = denominator * f.denominator;
        simplify();
        
        return fNew;
    }

    Fraction operator/(Fraction const &f) {
        Fraction fNew;
        fNew.numerator = numerator * f.denominator;
        fNew.denominator = denominator * f.numerator;
        simplify();

        return fNew;
    }

    Fraction& operator++() {
        numerator = numerator + denominator;
        simplify();
        return *this;
    }

    Fraction operator++(int) {
        Fraction fNew(numerator , denominator);
        numerator = numerator + denominator;
        simplify();
        fNew.simplify();
        return fNew;
    }

    void print() {
        cout << this -> numerator << " / " << this -> denominator << endl;
    }
};

int main () {
    Fraction f1(1,2);
    Fraction f2(1,3);

    Fraction f3;
    ++(++f1);
    f1.print();
    
}