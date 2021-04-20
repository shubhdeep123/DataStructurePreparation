#include<iostream>
using namespace std;

class Polynomial {
    public:
    int *degCoeff;
    int capacity;

    Polynomial () {
        degCoeff = new int[5];
        capacity = 5;

        for (int i=0; i<capacity; i++) {
            degCoeff[i] = 0;
        }
    }

    Polynomial (Polynomial const &p) {
        this -> degCoeff = new int[p.capacity];
        for (int i=0; i<p.capacity; i++) {
           this -> degCoeff[i] = p.degCoeff[i]; 
        }
        this -> capacity = p.capacity;
    }

    Polynomial operator=(Polynomial const &p) {
        this -> degCoeff = new int[p.capacity];
        for (int i=0; i<p.capacity; i++) {
           this -> degCoeff[i] = p.degCoeff[i]; 
        }
        this -> capacity = p.capacity;
    }

    void setCoefficient(int degree, int coefficient) {
        while (degree >= capacity) {
            int *newDegCoeff = new int[2*capacity];
            for (int i=0; i<capacity; i++) {
                newDegCoeff[i] = this -> degCoeff[i];
            }
            for (int i=capacity; i<2*capacity; i++) {
                newDegCoeff[i]=0;
            }
            delete [] degCoeff;
            this -> degCoeff = newDegCoeff;
            capacity *= 2;
        }
        degCoeff[degree] = coefficient;
    }

    Polynomial operator+ (Polynomial &p) {
        Polynomial pNew;
        int Max = max(this->capacity,p.capacity);
        
        if(Max == capacity) {
            for (int i=p.capacity; i<capacity; i++) {
                p.setCoefficient(i,0);
            }
        }

        if (Max == p.capacity) {
            for (int i=capacity; i<p.capacity; i++) {
                setCoefficient(i,0);
            }
        }

        Polynomial pNew;

        for (int i=0; i<Max; i++) {
            pNew.setCoefficient(i,degCoeff[i]+p.degCoeff[i]);
        }

        return pNew;
    }

    Polynomial operator- (Polynomial &p) {
        Polynomial pNew;
        int Max = max(this->capacity,p.capacity);
        
        if(Max == capacity) {
            for (int i=p.capacity; i<capacity; i++) {
                p.setCoefficient(i,0);
            }
        }

        if (Max == p.capacity) {
            for (int i=capacity; i<p.capacity; i++) {
                setCoefficient(i,0);
            }
        }

        Polynomial pNew;

        for (int i=0; i<Max; i++) {
            pNew.setCoefficient(i,degCoeff[i]-p.degCoeff[i]);
        }

        return pNew;
    }

    Polynomial operator* (Polynomial &p) {
        Polynomial pNew;

        for (int i=0; i<capacity; i++) {
            Polynomial pTemp;
            for(int j=0; j<p.capacity; j++) {
                pTemp.setCoefficient(i+j,degCoeff[i]*p.degCoeff[j]);
            }
            pNew = pNew + pTemp;
        }

        return pNew;
    }

    void print() {
        for (int i=0; i<capacity; i++) {
            if (degCoeff[i] == 0) {
                continue;
            }
            cout << degCoeff[i] << "x" << i << " ";
        }
        cout << endl;
    }


};

int main () {
    Polynomial p1;
    p1.setCoefficient(1,4);
    p1.setCoefficient(3,-1);
    p1.setCoefficient(6,8);
    p1.setCoefficient(5,2);
    p1.print();
}