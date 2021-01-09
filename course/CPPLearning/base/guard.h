//
// Created by JMChen on 2021/1/9.
//

#ifndef ALGORITHM_COMPETITION_TRAINING_GUARD_H
#define ALGORITHM_COMPETITION_TRAINING_GUARD_H

#include <cstring>

class Complex {
private:
    double re, im;
public:
    Complex(double r, double i) : re(r), im(i) {
    }

    Complex() {}

    double real() const {
        return re;
    }

    double imag() const {
        return im;
    }

    double fun(const Complex &c) {
        return c.re + c.im;
    }

    Complex &operator+=(const Complex &);//声明
};

inline Complex &Complex::operator+=(const Complex &complex) {
    this->re += complex.re;
    this->im += complex.im;
    return *this;
}

inline Complex operator+(const Complex &x, const Complex &y) {
    return Complex(x.real() + y.real(), x.imag() + y.imag());
}

inline Complex operator+(const Complex &x, const double y) {
    return Complex(x.real() + y, x.imag());
}

inline Complex operator+(const double x, const Complex &y) {
    return Complex(y.real() + x, y.imag());
}

inline Complex operator+(const Complex &x) {
    return x;
}

inline Complex operator-(const Complex &x) {
    return Complex(-x.real(), -x.imag());
}

class MakeString {
private:
    char *data1;
public:
    char *data;
    MakeString(const char *str);

    MakeString(const MakeString &str);//拷贝构造
    MakeString& operator=(const MakeString &str);//拷贝赋值

    ~MakeString();
};

inline MakeString::MakeString(const char *str) {
    if (str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    } else {//未指定初值
        data = new char[1];
        *data = '\0';
    }
}

//深拷贝
inline MakeString::MakeString(const MakeString &str) {
    data = new char[strlen(str.data) + 1];
    strcpy(data, str.data);
}

MakeString &MakeString::operator=(const MakeString &str) {
    if (this == &str) {//检测自我赋值，一定要写
        return *this;
    }
    delete[] data;
    data = new char[strlen(str.data) + 1];
    strcpy(data, str.data);
    return *this;
}

MakeString::~MakeString() {
    delete[] data;
}

#endif //ALGORITHM_COMPETITION_TRAINING_GUARD_H
