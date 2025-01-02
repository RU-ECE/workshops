#include <iostream>

int main() {
    for (int i = 0; i < 10; i++) {
        fork(); // split the process.  This is a denial of service attack. Allocate so many processes,
        // each using 4GB, that the machine appears to die. It might eventually come back
        // but are you willing to wait?
    }

    int n = 1024*1024*1024;
    int * p = new int[n]; // allocate 4GB of RAM, no problem so far...
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    // the above is doable, I have 32GB of RAM
}