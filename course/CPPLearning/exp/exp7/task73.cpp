#include "task73.h"

int main() {
    Complex<int> complex1(1, 2), complex2(2, 3), complex3, complex4;
    Complex<double> complex5(1.5, 2.2), complex6(4.2, 3.9), complex7, complex8;
    complex3 = complex1 + complex2;
    complex4 = complex1 - complex2;
    cout << complex3;
    cout << complex4;

    complex7 = complex5 + complex6;
    complex8 = complex5 - complex6;
    cout << complex7;
    cout << complex8;

    return 0;
}
