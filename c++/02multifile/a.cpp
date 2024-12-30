#include <iostream>
using namespace std;

void f(); // function prototype: somewhere out there is a function called f returning nothing

int main() {
    cout << "Hello, World!" << endl;
    f();
    return 0;
}