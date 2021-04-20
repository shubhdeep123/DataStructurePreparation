#include <iostream>
#include "templates.cpp"
using namespace std;

int main () {
    Pair<int> p1;
    p1.setX(10);
    p1.setY(20);
    cout << p1.getX() << endl;
    cout << p1.getY() << endl;
    
    Pair<double> p2;
    p2.setX(13.7);
    p2.setY(25.7);
    cout << p2.getX() << endl;
    cout << p2.getY() << endl;

    DiffPair <int, double> p3;
    p3.setX(18);
    p3.setY(16.5);
    cout << p3.getX() << " " << p3.getY() << endl;
}