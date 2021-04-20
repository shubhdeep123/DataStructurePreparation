#include <iostream>
using namespace std;

class Polynomial {
    int *degCoeff;      // Name of your array (Don't change this)
    int capacity;
    // Complete the class

    public:
    Polynomial() {
        degCoeff = new int[5];
        capacity = 5;
        for (int i=0; i<capacity; i++) {
            degCoeff[i] = 0;
        }
    }

    Polynomial(Polynomial const &p) {
        this -> degCoeff = new int[p.capacity];
        for(int i=0; i<p.capacity; i++) {
            this -> degCoeff[i] = p.degCoeff[i];
        }
        this -> capacity = p.capacity;
    }

    Polynomial& operator=(Polynomial const &p) {
        this -> degCoeff = new int[p.capacity];
        for(int i=0; i<p.capacity; i++) {
            this -> degCoeff[i] = p.degCoeff[i];
        }
        this -> capacity = p.capacity;
        return *this;
    }

    Polynomial& operator+(Polynomial const &p) {
        int size = capacity >= p.capacity? capacity : p.capacity;
        for (int i=0; i<size; i++) {
            degCoeff[i] += p.degCoeff[i];
        }
        return *this;
    }

    Polynomial& operator-(Polynomial const &p) {
        int size = capacity >= p.capacity? capacity : p.capacity;
        for (int i=0; i<size; i++) {
            degCoeff[i] -= p.degCoeff[i];
        }
        return *this;
    }

    // Polynomial operator*(Polynomial const &p) {
    //     Polynomial pNew;
    //     for (int i=0; i<capacity; i++) {
    //         for (int j=0; j<p.capacity; j++) {
    //             pNew.degCoeff[i+j] += degCoeff[i]*p.degCoeff[j]; 
    //         }
    //     }
    //     return pNew;
    // }

     Polynomial operator*( Polynomial  & p2){
     Polynomial p3;
     for(int i=0;i<capacity;i++)    //loop for *this
     {
         Polynomial p;
         for(int j=0;j<p2.capacity;j++)   ///loop for p2.degcoeff elemnts
         {
              p.setCoefficient(i+j,degCoeff[i]*p2.degCoeff[j]);     //   setting coeff at write place in arr
                                        //copying sideways to an alternate object  which I will return
         }
         p3=p3+p;
     }
    return p3; 
     
    }

    void print() const {
        for (int i=0; i<capacity; i++) {
            if (degCoeff[i] == 0) {
                continue;
            } else {
                cout << degCoeff[i] << "x" << i << " ";
            }
        }
    }

    void setCoefficient(int i, int element) {
        if (i >= capacity) {
            int *newDegCoeff = new int[2*capacity];
            for (int i=0; i<capacity; i++) {
                newDegCoeff[i] = degCoeff[i];
            }

            for(int j=capacity;j<2*capacity;j++){
                newDegCoeff[j]=0;
            }

            delete [] degCoeff;
            degCoeff = newDegCoeff;
            capacity *= 2;
            setCoefficient(i,element);  
        } else if (i < capacity) {
            degCoeff[i] = element;
        }
    }
    
};


int main () {
    Polynomial p1,p2;
    p1.setCoefficient(1,1);
    p1.setCoefficient(2,2);
    p2.setCoefficient(3,3);
    p2.setCoefficient(2,1);
    p1.print();
    cout << endl;
    p2.print();
    cout << endl;

    Polynomial p3 = p1*p2;

    p3.print();
    cout << endl;

}



