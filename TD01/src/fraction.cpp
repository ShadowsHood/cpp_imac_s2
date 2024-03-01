#include <iostream>
#include "fraction.hpp"
#include "utils.hpp"

std::ostream& operator<<(std::ostream& os, Fraction const& frac) {
    return os << frac.numerator << "/" << frac.denominator;
}

Fraction intToFrac (int const i, int const denominator) {
    Fraction frac {i*denominator, denominator};
    return frac;
}

Fraction operator+=(Fraction & frac1, Fraction const& frac2) {

    frac1.numerator = (frac1.numerator*frac2.denominator) + (frac2.numerator*frac1.denominator);
    frac1.denominator *= frac2.denominator;

    return frac1;
}
    Fraction operator+(Fraction frac1, Fraction const& frac2) {
        frac1 += frac2;
        return frac1;
    }
    Fraction operator+(const Fraction& frac, int const i) {
        return frac + intToFrac(i, frac.denominator);
    };
    Fraction operator+(int const i, const Fraction& frac) {
        return frac + i;
    };

Fraction operator-=(Fraction & frac1, Fraction const& frac2) {

    frac1.numerator = (frac1.numerator*frac2.denominator) - (frac2.numerator*frac1.denominator);
    frac1.denominator *= frac2.denominator;

    return frac1;
}
    Fraction operator-(Fraction frac1, Fraction const& frac2) {
        frac1 -= frac2;
        return frac1;
    }
    Fraction operator-(const Fraction& frac, int const i) {
        return frac - intToFrac(i, frac.denominator);
    };
    Fraction operator-(int const i, const Fraction& frac) {
        return frac - i;
    };

Fraction operator*=(Fraction & frac1, Fraction const& frac2) {

    frac1.numerator *= frac2.numerator;
    frac1.denominator *= frac2.denominator;

    return frac1;
}
    Fraction operator*(Fraction frac1, Fraction const& frac2) {
        frac1*=frac2;
        return frac1;
    }
    Fraction operator*(Fraction frac, int const i) {
        frac.numerator*=i;
        return frac;
    };
    Fraction operator*(int const i, const Fraction& frac) {
        return frac * i;
    };

Fraction operator/=(Fraction & frac1, Fraction const& frac2) {

    frac1.numerator *= frac2.denominator;
    frac1.denominator *= frac2.numerator;

    return frac1;
}
    Fraction operator/(Fraction frac1, Fraction const& frac2) {
        frac1/=frac2;
        return frac1;
    }
    Fraction operator/(Fraction frac, int const i) {
        frac.denominator*=i;
        return frac;
    };
    Fraction operator/(int const i, const Fraction& frac) {
        return frac / i;
    };

bool operator==(Fraction const& frac1, Fraction const& frac2) {
    return (frac1.numerator*frac2.denominator == frac2.numerator*frac1.denominator) ? true : false;
}
bool operator!=(Fraction const& frac1, Fraction const& frac2) {
    return (frac1.numerator*frac2.denominator != frac2.numerator*frac1.denominator) ? true : false;
}
bool operator<(Fraction const& frac1, Fraction const& frac2) {
    return (frac1.numerator*frac2.denominator < frac2.numerator*frac1.denominator) ? true : false;
}
bool operator>(Fraction const& frac1, Fraction const& frac2) {
    return (frac1.numerator*frac2.denominator > frac2.numerator*frac1.denominator) ? true : false;
}
bool operator<=(Fraction const& frac1, Fraction const& frac2) {
    return (
        frac1.numerator*frac2.denominator < frac2.numerator*frac1.denominator || 
        frac1.numerator*frac2.denominator == frac2.numerator*frac1.denominator
    ) ? true : false;
}
bool operator>=(Fraction const& frac1, Fraction const& frac2) {
    return (
        frac1.numerator*frac2.denominator > frac2.numerator*frac1.denominator || 
        frac1.numerator*frac2.denominator == frac2.numerator*frac1.denominator
    ) ? true : false;
}

float to_float(Fraction const& frac) {
    return static_cast<float>(frac.numerator) / frac.denominator;
}

Fraction::operator float() const {
    return static_cast<float>(numerator) / denominator;
}

//valeur absolue
Fraction abs(Fraction frac) {
    frac.numerator = std::abs(frac.numerator);
    frac.denominator = std::abs(frac.denominator);
    return frac;
} 

//arrondi supérieur
int ceil(Fraction const& frac) {
    int ceilNum {static_cast<int>(std::ceil(simplify(frac)))};
    return ceilNum;
} 

//arrondi inférieur
int floor(Fraction const& frac) {
    int floorNum {static_cast<int>(std::floor(simplify(frac)))};
    return floorNum;
}

//arrondi
int round(Fraction const& frac) {
    int roundNum {static_cast<int>(std::round(simplify(frac)))};
    return roundNum;
}