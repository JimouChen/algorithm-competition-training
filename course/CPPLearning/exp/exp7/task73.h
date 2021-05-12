#ifndef ALGORITHM_COMPETITION_TRAINING_TASK73_H
#define ALGORITHM_COMPETITION_TRAINING_TASK73_H
#include <iostream>
using namespace std;

template<class T>
class Complex {
private:
    T real;
    T image;
public:
    Complex(T rl = 0, T im = 0);
    Complex<T> operator+(Complex<T> &a);
    Complex<T> operator-(Complex<T> &a);
    friend ostream & operator<<(ostream & out,const Complex<T> &obj){
        out << obj.real;
        if (obj.image < 0)out << obj.image << "i" << endl;
        else if (obj.image > 0)out << "+" << obj.image << "i" << endl;
        else out << endl;
        return out;
    };
};

template<class T>
Complex<T>::Complex(T rl, T im) : real(rl), image(im) {}

template<class T>
Complex<T> Complex<T>::operator+(Complex<T> &a) {
    Complex<T> complex;
    complex.real = real + a.real;
    complex.image = image + a.image;
    return complex;
}

template<class T>
Complex<T> Complex<T>::operator-(Complex<T> &a) {
    Complex<T> complex;
    complex.real = real - a.real;
    complex.image = image - a.image;
    return complex;
}
//
//template<class T>
//ostream &operator<<(ostream &out, const Complex<T> &obj) {
//    out << obj.real;
//    if (obj.image < 0)out << obj.image << "i" << endl;
//    else if (obj.image > 0)out << "+" << obj.image << "i" << endl;
//    else out << endl;
//    return out;
//}


#endif
