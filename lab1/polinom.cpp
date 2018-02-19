#include "polinom.h"
#include "math.h"

Polinom::Polinom(number num1, number num2, number num3) {
    a = num1;
    b = num2;
    c = num3;
}

number Polinom::value(number x) {
    return a * x * x + b * x + c;
}

int Polinom::roots(number* nums) {
    number d = b * b - 4 * a * c;
    if (d > 0) {
        nums[0] = (-b + sqrt(d)) / (2 * a);
        nums[1] = (-b - sqrt(d)) / (2 * a);
        return 2;
    } else if (d == 0) {
        nums[0] = -b / (2 * a);
        return 1;
    } else {
        return 0;
    }
}

