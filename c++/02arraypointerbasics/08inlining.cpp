#include <iostream>
using namespace std;
// this function will be inlined automatically because C++ can do it
int f(int x) { return x*8; }

int g(int x);

double h(double a, double b, int n) {
    for (int i = 0; i < n; i++) {
        a = a + b;
        b = b + a+ .1;
        a = a * 2.1;
        b = b * 0.9;
    }
    return (a + b)*.4;
}

double add(double a, double b) { return a + b; }

int main() {
    int y = f(2); // calling a function takes time
    int x;
    cin >> x;
    cout << f(x);
    //turns into: int y = 4; // c++ will eliminate the function call, and evaluate the constant expression at compile time
    int z = g(3); // this must call a function, because C++ IS NOT CLAIRVOYANT
     //int y= 2*8; // %rsi=16
    cout << y;
    cout << h(1.2, 3.4, 59);


    cout << h(2.3, 1.4, 5900);

}