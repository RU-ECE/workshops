#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

int main() {
    int a = 10;      // 32-bits? size(a) >= 16 bits
    long int b = 123456789012345678L; // 64-bits?  size(long int) >= size(int)
    short int c = 32767; // 16-bits?
    long long d = 123456789012345678LL; // 64-bits

    bool e = true;      // true or false
    float f = 1.1;    // 32-bit floating point
    double g = 1.2;   // 64-bit floating point
    char h = 'a';
    string i;



    uint32_t p = 123456789; // always 32-bits, unsigned
    uint64_t q = 1234567890123456789; // always 64-bits, unsigned
    int32_t r = -123456789;  // always 32-bits, signed
    int64_t s = -123456789012345678;  // always 64-bits, signed
    int8_t t = -128;
    int16_t u = -32768;
    cout << q << '\n';
    cout << s << '\n';
    
}