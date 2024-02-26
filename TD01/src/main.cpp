#include <iostream>
#include <string>
#include <vector>
#include "fraction.hpp"
#include "utils.hpp"
#include <cstdlib>

using namespace std;

int main()
{
    std::cout << "TD 01" << std::endl;

    Fraction f1 {2, 2};
    Fraction f2 {2, 3};
    // Fraction f1 {rand(), rand()};
    // Fraction f2 {rand(), rand()};

    cout << (f1) << endl;
    cout << (f2) << endl;

    cout << "Calculs :" << endl;

    cout << (f1 + f2) << endl;
    cout << (f1 - f2) << endl;
    cout << (f1 * f2) << endl;
    cout << (f1 / f2) << endl;

    cout << "Versions simplifiées :" << endl;

    cout << (simplify(f1 + f2)) << endl;
    cout << (simplify(f1 - f2)) << endl;
    cout << (simplify(f1 * f2)) << endl;
    cout << (simplify(f1 / f2)) << endl;

    return 0;
}