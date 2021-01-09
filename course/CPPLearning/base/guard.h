//
// Created by JMChen on 2021/1/9.
//

#ifndef ALGORITHM_COMPETITION_TRAINING_GUARD_H
#define ALGORITHM_COMPETITION_TRAINING_GUARD_H

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




#endif //ALGORITHM_COMPETITION_TRAINING_GUARD_H
