#include <iostream>

int main() {
    int x[128LL*1024*1024*1024]; // this should not work, asking for WAY too much memory
//    int* a = new int[1024*1024*1024]; // asking for memory on the heap
}