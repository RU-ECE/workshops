#include <iostream>

class fraction {
public:
    fraction(int n = 0, int d = 1) : num(n), den(d) { }
    friend fraction add(fraction f1, fraction f2);
    friend fraction operator +(fraction f1, fraction f2);
    fraction add(fraction f2) const {
        fraction ans(this->num * f2.den + this->den * f2.num, this->den * f2.den);
        return ans;
    }
    static fraction add(fraction f1, fraction f2) {
        fraction ans(f1.num * f2.den + f1.den * f2.num, f1.den * f2.den);
        return ans;
    }
private:
    const int num;
    const int den;
};

fraction add(fraction f1, fraction f2) {
    fraction ans(f1.num * f2.den + f1.den * f2.num, f1.den * f2.den);
    return ans;
}

fraction operator +(fraction f1, fraction f2) {
    fraction ans(f1.num * f2.den + f1.den * f2.num, f1.den * f2.den);
    return ans;
}

int main() {
    fraction f1(1,2);
    fraction f2(2,3);
    fraction f3 = f1 + f2; // operator + (f1,f2)
    fraction f4 = add(f1, f2);
    fraction f5 = f1.add(f2);
    fraction f6 = fraction::add(f1, f2);
    return 0;
}