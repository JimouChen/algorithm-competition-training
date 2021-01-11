#pragma once

#include <iostream>
#include "guard.h"

using namespace std;

class Account {
public:
    static double rate;

    static void set_rate(const double &x) {
        rate = x;
    }
};

double Account::rate = 5.0;


template<typename T>
class People {
private:
    T a, b;
public:
    People(T a1, T b1) : a(a1), b(b1) {}

    T function(T a1, T b1) {
        return a1 * b1;
    }
};

//函数模板
template<typename T>
T &min(T &a1, T &b1) {
    return a1 < b1 ? a1 : b1;
}

class A {
public:
    int age;

    A(int age1) : age(age1) {
        cout << "age birth is " << age << endl;
    }

    ~A() {
        cout << "over A class\n";
    }
};

class Dad {
private:
    string name;
public:
    Dad(string str) : name(str) {
        cout << "father is " << name << endl;
    }

    ~Dad() {
        cout << "over father\n";
    }
};

class Son : public Dad {
private:
    string name;
    A age;
public:
    Son(const string &str, const string &name1, const A &age1) : Dad(str), name(name1), age(age1) {
        cout << "son is " << name << endl;
    }


    ~Son() {
        cout << "over son\n";
    }

    void speak() {
        cout << "hello\n";
    }
};

int main() {
    Son("Nick", "Tom", 20);



//    People<int> people1(2, 3);
//    People<double> people2(1.2, 3.4);
//    Account account;
//    cout << Account::rate << endl;
//    Account::set_rate(9);
//    cout << Account::rate << endl;
//
//    int a = 9, b = 7;
//    float c = 1, d = 3;
//    cout << min(a, b) << endl;
//    cout << min(c, d) << endl;





//    Complex complex(2, 1);
//    Complex complex2(2, 1);
//    Complex c1;
//    double d = 3;
//    cout << c1.fun(complex) << endl;
//    Complex c2 = complex + complex2;
//    Complex c3 = complex + d;
//    complex+=complex2;
//    cout << c2.real() << " " << c2.imag()<<"\n";
//    cout << c3.real() << " " << c3.imag()<<"\n";
//    cout << complex.real() << " " << complex.imag()<<"\n";
//    //test MakeString
//    MakeString *m1 = new MakeString("hello");
//    MakeString m2("");
//    MakeString m3("world");
//    cout<<m3.data<<endl;
//    cout<<m1->data<<endl;
//    m2 = m3;
//    cout<<m2.data<<endl;
//    MakeString m4(m3);
//    cout<<m4.data<<endl;


    return 0;
}