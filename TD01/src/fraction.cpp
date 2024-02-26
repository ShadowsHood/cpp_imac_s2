#include <iostream>
#include "fraction.hpp"

Fraction operator+(Fraction frac1, Fraction const& frac2) {

    frac1.numerator = (frac1.numerator*frac2.denominator) + (frac2.numerator*frac1.denominator);
    frac1.denominator *= frac2.denominator;

    return frac1;
}

Fraction operator-(Fraction frac1, Fraction const& frac2) {

    frac1.numerator = (frac1.numerator*frac2.denominator) - (frac2.numerator*frac1.denominator);
    frac1.denominator *= frac2.denominator;

    return frac1;
}

Fraction operator*(Fraction frac1, Fraction const& frac2) {

    frac1.numerator *= frac2.numerator;
    frac1.denominator *= frac2.denominator;

    return frac1;
}

Fraction operator/(Fraction frac1, Fraction const& frac2) {

    frac1.numerator *= frac2.denominator;
    frac1.denominator *= frac2.numerator;

    return frac1;
}

std::ostream& operator<<(std::ostream& os, Fraction const& frac) {
    return os << frac.numerator << "/" << frac.denominator;
}
