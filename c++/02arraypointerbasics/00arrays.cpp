#include <iostream>

using namespace std;

void f() {
    int x;
    double y = 1.23456789012345;
    float a[10]; // a[0] through a[9]
    a[0] = 1.5;
    a[9] = 9.8;
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    int b[] = {1, 2, 3}; // b[0] = 1, b[1] = 2, b[2] = 3
    int c[100] = {1, 2, 3}; // c[0] = 1, c[1] = 2, c[2] = 3, all the rest = 0
    float d[100] = {0}; // d[0] = 0, and everything else initialize everything to zero

    double e[3][4]; // a single chunk of 3*4 doubles in memory
    // we think of this as 3 rows of 4 columns each
    uint64_t f[4][5][6]; // a single chunk of 4*5*6 uint64_t in memory
    cout << "sizeof(b)=" << sizeof(b) << "\n";
    cout << "sizeof(c)=" << sizeof(c) << "\n";
    cout << "sizeof(d)=" << sizeof(d) << "\n";
    cout << "sizeof(e)=" << sizeof(e) << "\n";
    cout << "sizeof(f)=" << sizeof(f) << "\n";
}

void g() {
    int a[2*1024*1024]; // 4 MB
    int b[1024];
    int c[1024*1024];
    for (int i = 0; i < 1024*1024; i++) {
        a[i] = i;
    }
    for (int i = 0; i < 1024*1024; i++) {
        b[i] = i;
    }
    for (int i = 0; i < 1024*1024; i++) {
        c[i] = i;
    }

}

int main() {
    f();
    g();
    return 0;
}