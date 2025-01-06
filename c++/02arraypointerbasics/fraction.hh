#pragma once

#include <iostream>

class fraction {
public:
    fraction(int n, int d) : num(n), den(d) { }
    friend std::ostream& operator <<(std::ostream& s, fraction f) {
        return s << f.num << '/' << f.den;
    }
    friend fraction operator +(fraction f1, fraction f2);
private:
    int num;
    int den;
};
