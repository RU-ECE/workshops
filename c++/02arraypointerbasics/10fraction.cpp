#include "fraction.hh"
int main() {
    fraction f1(1,2);
    fraction f2(2,3);
    std::cout << f1 << '\n';
    fraction f3 = f1 + f2;
    return 0;
}