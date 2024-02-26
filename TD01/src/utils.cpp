#include <iostream>
#include "fraction.hpp"

int gcd (int number1, int number2) {

    if(number1 < number2) {
        int temp {number1};
        number1 = number2;
        number2 = temp;
    }

    int calcul_cgd {number2};
    while (number1 % number2 != 0) {
        calcul_cgd = number1 % number2;
        number1 = number2;
        number2 = calcul_cgd;
    }

    return calcul_cgd;
}

Fraction simplify(Fraction frac) {

    int temp_gcd = gcd(frac.numerator, frac.denominator);

    frac.numerator /= temp_gcd;
    frac.denominator /= temp_gcd;

    return frac;
}