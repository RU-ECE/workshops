#include <iostream>

using namespace std;

void f() {
    int * a = new int[100];

}
int main() {
    int *p = new int[4*1024*1024]; // 4M elements * 4byte = 16MB

    delete [] p; // give back 16MB

    for (int i = 0; i < 1000000; i++) {
        f(); // memory leak.  Eventually, I will run out of memory
    }


    int *q = new int; // allocate 4 bytes
    q++; // make q point to next memory location

    delete q; // give back 4 bytes

    return 0;
}