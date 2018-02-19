#ifndef POLINOM_H
#define POLINOM_H

#include "number.h"

class Polinom
{

    number a;
    number b;
    number c;

public:
    Polinom(number, number, number);
    number value(number);
    int roots(number*); //return number of roots
};

#endif // POLINOM_H
