#include <iostream>
using namespace std;

class Fraction { // a class is a type. it is a specficaition for an object
private:
   int num, den; // instance variables (in C++ and Java member variables)
public:
// constructors are special functions with NO RETURN TYPE
   Fraction() { num = 0; den = 1; }
   Fraction(int n) { num = n; den = 1; }
   Fraction(int n, int d) { num = n; den = d; }
   // in order to promise not to change the object, put const after the parameters
   void print() const { cout << num << "/" << den; }

   // f is not a const function! f returns a number that is constant!
   // returning a const value is meaningless since it is COPIED!!!
   const int f() { num = 99; return num; }
};

int main() {
    int x = 0; // auto variables are undefined values

    // an object is an instance of a class
    Fraction f1; // f1.num = 0 f1.den = 1
    Fraction f2(2); // f2.num = 2 f2.den =
    Fraction f3(2, 3); // f2.num = 2 f2.den = 3
//Error: no matching function    Fraction f4(1,2,3);

    f1.print();
    const Fraction f4(1,2); // F4 = 1/2
    f4.print();
    return 0;
}