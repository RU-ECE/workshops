#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

int main() {
    for (int i = 0; i < 10; i++) {
        cout << i << ' '; // 0 1 2 3 4 5 6 7 8 9 
    }
    cout << '\n';
    // codeium, stop interfering!
    for (int i = 5; i >  0; i--) {
        cout << i << ' ';
    }
    cout << '\n';
    // <  >   <=  >=  ==  != 
    // note: => is not legal
    for (int i = 5; i >= 0; i--) { // some editors will convert this to unicode symbol ≥
        cout << i << ' ';
    }
    cout << '\n';

    for (uint32_t i = 3; i >= 0; i--) {
        cout << i << ' ';
    }
    cout << '\n';


}