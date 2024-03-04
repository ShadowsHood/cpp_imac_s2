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



    //Valeurs tests à titre indicatif personnel
    //Changer et remplacer par n'importe quelle fraction/fonction/... voulue






    Fraction f1 {2, 2};
    Fraction f2 {2, 3};
    // Fraction f1 {rand(), rand()};
    // Fraction f2 {rand(), rand()};

    cout << (f1) << endl;
    cout << (f2) << endl;

    cout << "Calculs par opérateurs directs :" << endl;

    cout << (simplify(f1 + f2)) << endl;
    cout << (simplify(f1 - f2)) << endl;
    cout << (simplify(f1 * f2)) << endl;
    cout << (simplify(f1 / f2)) << endl;

    cout << "Résultats en float :" << endl;

    cout << (to_float(f1 + f2)) << endl; //1.666
    cout << (to_float(f1 - f2)) << endl; //0.333
    cout << (to_float(f1 * f2)) << endl; //0.666
    cout << (to_float(f1 / f2)) << endl; //1.5

    cout << "Résultats en float frac init :" << endl;

    cout << to_float(f1) << endl; //1
    cout << to_float(f2) << endl; //0.666

    cout << "Résultats en float frac static cast :" << endl;

    float fl1 {static_cast<float>(f1)}; // conversion explicite avec static_cast
    float fl2 {static_cast<float>(f2)}; // conversion explicite avec static_cast
    cout << fl1 << endl;
    cout << fl2 << endl;

    cout << "Tests :" << endl;

    Fraction f3 {2, 3};
    Fraction f4 {-2, 3};
    Fraction f5 {2, -3};
    Fraction f6 {-2, -3};

    cout << "F3 :" << endl;
    cout << "----- " << f3 << endl;
    cout << "----- " << to_float(f3) << endl;
    cout << "----- " << abs(f3) << endl;
    cout << "----- " << ceil(f3) << endl;
    cout << "----- " << floor(f3) << endl;
    cout << "----- " << round(f3) << endl;
    cout << "F4 :" << endl;
    cout << "----- " << f4 << endl;
    cout << "----- " << to_float(f4) << endl;
    cout << "----- " << abs(f4) << endl;
    cout << "----- " << ceil(f4) << endl;
    cout << "----- " << floor(f4) << endl;
    cout << "----- " << round(f4) << endl;
    cout << "F5 :" << endl;
    cout << "----- " << f5 << endl;
    cout << "----- " << to_float(f5) << endl;
    cout << "----- " << abs(f5) << endl;
    cout << "----- " << ceil(f5) << endl;
    cout << "----- " << floor(f5) << endl;
    cout << "----- " << round(f5) << endl;
    cout << "F6 :" << endl;
    cout << "----- " << f6 << endl;
    cout << "----- " << to_float(f6) << endl;
    cout << "----- " << abs(f6) << endl;
    cout << "----- " << ceil(f6) << endl;
    cout << "----- " << floor(f6) << endl;
    cout << "----- " << round(f6) << endl;




    return 0;
}