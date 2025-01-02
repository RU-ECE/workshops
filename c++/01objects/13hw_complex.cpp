#include <iostream>
using namespace std;

class complex {
    private:
        double real, imag;
    public:
    friend complex operator -(complex c) { // unary operator -
        return complex(-c.real, -c.imag);
    }
    //friend complex operator -(complex a, complex b) {
    //}
};

int main() {
    complex a(1.5,2.5);
    complex b(3.0); // imag = 0
    complex c; // real = imag = 0 Notice, NO PARENTHESES for no parameters
    complex d(); // d is NOT AN OBJECT it is a prototype of a function that returns a complex object

    complex e = a + b; // define complex addition! (use a friend operator)
    complex f = a - b;
    complex g = a * b;
    complex h = -a; // unary operator
    cout << "e=" << e << '\n';
    cout << "f=" << f << '\n';
    cout << "g=" << g << '\n';


    return 0;
}