#include <iostream>
#include <iomanip>
/*
    Codeium: STOP INTERFERING

    sum1: sum the numbers from a to b inclusive
    sum2a: sum the fractions 1/1 + 1/2 + 1/3 + 1/4 + ... + 1/100 =~ 5.18...
    sum2b: sum the fractions 1/100 + 1/99 + ... + 1/1 =~ 5.18...
    sum3: mystery sum 1/(1*1) + 1/(2*2) + 1/(3*3) + 1/(4*4) + ... + 1/(n*n)
*/

int sum1 (int a, int b) {

}

float sum2(int a, int b) {
    float sum = 0;
}

// compute the mystery sum forwards
float sum3a(int n) {

}
// compute the mystery sum backwards
float sum3b(int n) {

}


int main() {
    int sum = 0;
    for (int i = 0; i <= 100; i++) {
        sum += i;
    }
    cout << sum << endl;

    cout << sum1(5, 50) << '\n';
    cout << sum1(1, 1000000) << '\n'; // wrong, why?
    float s1 = sum2a(100);
    float s2 = sum2b(100);
    cout << "s1=" << s1 << ", s2=" << s2 << ", diff=" << (s1-s2) << endl;
    for (int n = 1; n <= 1000000; n *= 10) {
       cout << sqrt(6*sum3a(100000)) << '\n';
       cout << sqrt(6*sum3b(100000)) << '\n';
    }
    return 0;

}