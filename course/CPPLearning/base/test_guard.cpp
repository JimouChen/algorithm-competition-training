#pragma once

#include <iostream>
#include "guard.h"

using namespace std;

int main() {
    Complex complex(2, 1);
    Complex complex2(2, 1);
    Complex c1;
    double d = 3;
    cout << c1.fun(complex) << endl;
    Complex c2 = complex + complex2;
    Complex c3 = complex + d;
    complex+=complex2;
    cout << c2.real() << " " << c2.imag()<<"\n";
    cout << c3.real() << " " << c3.imag()<<"\n";
    cout << complex.real() << " " << complex.imag()<<"\n";
    //test MakeString
    MakeString *m1 = new MakeString("hello");
    MakeString m2("");
    MakeString m3("world");
    cout<<m3.data<<endl;
    cout<<m1->data<<endl;
    m2 = m3;
    cout<<m2.data<<endl;
    MakeString m4(m3);
    cout<<m4.data<<endl;


    return 0;
}