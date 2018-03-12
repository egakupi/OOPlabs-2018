#include "complex.h"
#include "math.h"

Complex::Complex(double x, double y) {
    re = x;
    im = y;
}

QString Complex::toString() {
    return QString().setNum(re) + (im > 0) ? '+' : ''  + QString.setNum(im) + 'i';
}

Complex Complex::operator +(Complex c) {
    return Complex(re + c.re, im + c.im);
}

Complex Complex::operator -(Complex c) {
    return Complex(re - c.re, im - c.im);

}

Complex operator -() {
    return Complex(-re, -im);
}

Complex Complex::operator *(Complex c) {
    return Complex(re * c.re - im * c.im, re * c.im + c.re * im);
}

bool Complex::operator >(int x) {
    return true;
}

Complex operator *(int x, Complex c) {
    return Complex(x * c.re, x * c.im);
}

Complex sqrt(Complex c) {
    double r = sqrt(re * re + im * im);
    double alpha = atan2(im, re);
    return Complex(sqrt(r) * cos(alpha / 2), sqrt(r) * sin(alpha /2));
}
