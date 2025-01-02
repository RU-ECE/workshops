#include <iostream>

using namespace std;
int main() {
    int *p; // p is a pointer to int (pointing to random address)
    //cout << *p; // *p is what p is pointing to
    // looking here probably crashes
    int a = 5;
    p = &a; // p points to location of variable a
    *p = 6; // a=6
    cout << a << endl;

    return 0;
}