#include <iostream>

class fraction {
public:
// constructor automatically defines how to convert from int to fraction
    fraction(int n) : num(n), den(1) {}
    fraction(int n, int d) : num(n), den(d) {}
    friend fraction operator +(fraction f1, fraction f2) {
        return fraction(f1.num*f2.den + f2.num*f1.den, f1.den*f2.den);
    }
    fraction operator -(fraction f2) const {
        return fraction(num*f2.den + f2.num*den, den*f2.den);
    }
    operator float() const { return float(num)/float(den); }
private:
    int num;
    int den;
};

int main() {
    fraction f1(1, 2);
    fraction f2(2, 3);
    fraction f3 = f1 + f2;
    fraction f4 = f1 - f2;
    fraction f5 = f1 + 1; // f1 + fraction(1)
    fraction f6 = 1 + f1; // fraction(1) + f1
    fraction f7 = f1 - 1; // f1.operator-(1)f1 - fraction(1)
    //fraction f8 = 1 - f1;  ERROR: left hand side MUST BE AN OBJECT of type fraction
    float f = f1; // convert 1/2 to 0.5
    return 0;
}