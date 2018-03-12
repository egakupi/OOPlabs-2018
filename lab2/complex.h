#ifndef COMPLEX_H
#define COMPLEX_H
#include "qstring.h"


class Complex
{

    double re;
    double im;
public:
    Complex(double = 0.0, double = 0.0);
    QString toString();
    Complex operator +(Complex);
    Complex operator -(Complex);
    Complex operator *(Complex);
    bool operator >(int);
    Complex operator -();

    friend Complex operator *(int, Complex);
    friend Complex sqrt(Complex);

};
#endif // COMPLEX_H
