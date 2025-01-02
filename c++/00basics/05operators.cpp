#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

int main() {
    int a = 10;      // 32-bits? size(a) >= 16 bits
    long int b = 3; // 64-bits?  size(long int) >= size(int)
    short int c = 32767; // 16-bits signed?
    long long d = 100; // 64-bits

    a = a + 3;
    b = a + b; // type promotion  convert a to long int, and add 64-bits
    c++; // c = c + 1 (overflows, -32768)
    cout << c << '\n';

    a = 3 - 4;
    cout << a << '\n';
    b = 100000 * 100000;
    cout << b << '\n';
    c = 3 / 4; // constant expressions are evaluated at compile time
    cout << c << '\n';
    d = 3 % 4; // 3 MOD 4
    cout << d << '\n';
    cout << (2 % 3 + 3%4 + 4%4 + 5%4) << '\n'; // ??

    uint32_t e = 3 - 4; // -1 = 11111111111111111111111111111111 = 2^32 - 1 = 4294967295
    cout << e << '\n';
    uint64_t f = 100000L * 100000; // example of type promotion. Codeium, stop interfering!
    cout << f << '\n';
}