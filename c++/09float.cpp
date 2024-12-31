#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float evalpolynomial(float x, float a, float b, float c, float d) {
    return a*pow(x, 3) + b*pow(x,2) + c*pow(x,1) + d;
}

float evalpolynomial2(float x, float a, float b, float c, float d) {
    return a*pow(x, 3) + b*pow(x,2) + c*x + d;
}

// using Horner's form
float evalpolynomial3(float x, float a, float b, float c, float d) {
    return ((a*x + b)*x + c)*x + d;
}


int main() {

    float a = 1; // a = 1.0f
    float b = 2.5; // a = 2.5000000f
    float c = 0;
    float d = a + b;

    // roundoff error, and numbers that aren't exactly representable
    // s = sign (+/-) 0=positive
    // e = exponent -127 .. +127
    // m = mantissa digits of the number
    // seeeeeeeemmmmmmmmmmmmmmmmmmmmmmm
    //         .1 = 1/2
    //         .01 = 1/4
    //         .001 = 1/8
    //      101.110 = 5.75
    cout << setprecision(8);
    for (float x = 0; x <= 10; x += 0.1) {
        cout << x << ' ';
    }
    cout << '\n';

    d = a + b;
    d = a - b;
    d = a * b;
    d = a / b; // there is no mod for floating point fmod(a, b) = a - b * floor(a/b)
    d = pow(a,b); // there is no exponentiation operator in C, ^ is for bitwise XOR
    d = pow(a, 2); // d = a * a
    d = pow(a, .16);
    // sin, cos, tan, asin, acos, atan, atan2, sinh, cosh, tanh, asinh, acosh, atanh
    // sqrt, cbrt, pow, exp, log, log10, log2
    d += 0.1;
    d -= 0.1;
    d *= 10;
    d /= 10;
    d = floor(d); // round down
    d = ceil(d); // round up
    d = round(d); // round off to nearest (0.5 round up)
    d = trunc(d); //?
    d = fabs(d); // absolute value
    d = fmod(d, 2);

    float sum = 0;
    for (int i = 1; i <= 10; i++) {
        sum += 1.0/i; // 1/1 + 1/2 + 1/3 + 1/4 + 1/5 + 1/6 + 1/7 + 1/8 + 1/9 + 1/10

    float sum2 = 0;
    for (float i = 1; i <= 10; i++) {
        sum += 1/i; // 1/1 + 1/2 + 1/3 + 1/4 + 1/5 + 1/6 + 1/7 + 1/8 + 1/9 + 1/10
    float sum3 = 0;
    for (float i = 1; i <= 10; i++) {
        sum += 1.0f/i; // 1/1 + 1/2 + 1/3 + 1/4 + 1/5 + 1/6 + 1/7 + 1/8 + 1/9 + 1/10

    return 0;
}