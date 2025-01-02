#include <iostream>
using namespace std;

class Fraction
{ // a class is a type. it is a specficaition for an object
private:
    int num, den; // instance variables (in C++ and Java member variables)
public:
    Fraction(int n = 0, int d = 1)
    {
        num = n;
        den = d;
    }
    // in order to promise not to change the object, put const after the parameters
    void print() const { cout << num << "/" << den; }
    friend ostream &operator<<(ostream &s, Fraction f) {
        s << f.num << '/' << f.den;
        return s;
    }
};

int main() {
    const Fraction f1; // f1.num = 0 f1.den = 1
    Fraction f2(2);    // f2.num = 2 f2.den =
    Fraction f3(2, 3); // f2.num = 2 f2.den = 3
    cout << f1 << ' ' << f2 << ' ' << f3 << '\n';
    return 0;
}