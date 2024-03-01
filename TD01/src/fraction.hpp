#pragma once

struct Fraction
{
    int numerator {0};
    int denominator {1};

    operator float() const;
};

std::ostream& operator<<(std::ostream& os, Fraction const& frac);

Fraction intToFrac (int const i, int const denominator);

Fraction operator+=(Fraction & frac1, Fraction const& frac2);
    Fraction operator+(Fraction frac1, Fraction const& frac2);
    Fraction operator+(const Fraction& frac, int const i);
    Fraction operator+(int const i, const Fraction& frac);

Fraction operator-=(Fraction & frac1, Fraction const& frac2);
    Fraction operator-(Fraction frac1, Fraction const& frac2);
    Fraction operator-(const Fraction& frac, int const i);
    Fraction operator-(int const i, const Fraction& frac);

Fraction operator*=(Fraction & frac1, Fraction const& frac2);
    Fraction operator*(Fraction frac1, Fraction const& frac2);
    Fraction operator*(Fraction frac, int const i);
    Fraction operator*(int const i, const Fraction& frac);

Fraction operator/=(Fraction & frac1, Fraction const& frac2);
    Fraction operator/(Fraction frac1, Fraction const& frac2);
    Fraction operator/(Fraction frac, int const i);
    Fraction operator/(int const i, const Fraction& frac);

bool operator==(Fraction const& frac1, Fraction const& frac2);

bool operator!=(Fraction const& frac1, Fraction const& frac2);

bool operator<(Fraction const& frac1, Fraction const& frac2);

bool operator>(Fraction const& frac1, Fraction const& frac2);

bool operator<=(Fraction const& frac1, Fraction const& frac2);

bool operator>=(Fraction const& frac1, Fraction const& frac2);

float to_float(Fraction const& frac);

Fraction abs(Fraction frac);
int ceil(Fraction const& frac);
int floor(Fraction const& frac);
int round(Fraction const& frac);