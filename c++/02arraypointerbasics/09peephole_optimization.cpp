#include <iostream>

using namespace std;
int main() {
    uint64_t a, b;
    cin >> a >> b;
    int c = a * 8; // should optimize to a << 3
    uint64_t d = a / 32; // a >> 5
    uint64_t e = a % 64; // a & 0x3F
    // optimizer will COMPLETELY ELIMINATE THESE VARIABLES since they aren't used
    cout << c << " " << d << " " << e << endl;
    return 0;
}