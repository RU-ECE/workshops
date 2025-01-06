#include <iostream>

int f(int x) {
    return x + 1;
}

float f(float x) {
    return x*x;
}

double f(double a, double b) {
    return a + b;
}

double longer(int x, double a, double b, double c) {
    return x*(a+b+c);
}

void arraythingy(const int x[], double y, double a[], int z) {
    
}
#if 0
// illegal to have the same name for two functions with the same signature
void h(int x) {

}

int h(int x) {
    return x;
}
#endif

int main() {
    int y = f(2);
    float y2 = f(3);
    float y3 = f(y2);
    double y4 = f(1.5, 2.5);
    float y5 = float(f(1.5, 2.5)); // calls the double precision function, converts
}