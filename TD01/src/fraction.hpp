#pragma once

struct Fraction
{
    unsigned int numerator {0};
    unsigned int denominator {1};
};

Fraction operator+(Fraction frac1, Fraction const& frac2);

Fraction operator-(Fraction frac1, Fraction const& frac2);

Fraction operator*(Fraction frac1, Fraction const& frac2);

Fraction operator/(Fraction frac1, Fraction const& frac2);

std::ostream& operator<<(std::ostream& os, Fraction const& frac);