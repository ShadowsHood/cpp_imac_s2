#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include "npi.hpp"

int main() {
    std::cout << "TD 03 - Ex 01" << std::endl;

    std::string user_npi {};

    std::cout << "Entrez un calcul en NPI : ";
    std::getline(std::cin, user_npi);

    std::vector<Token> tokens {infix_to_npi_tokens(user_npi)};
    display_tokens(tokens);
    // std::cout << "Résultat : " << npi_evaluate(tokens) << std::endl;

    return 0;
}