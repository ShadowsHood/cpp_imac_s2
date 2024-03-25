#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include "hash.hpp"

int main() {
    std::cout << "TD 05 - Ex 01" << std::endl;

    std::string user_str {};

    std::cout << "Entrez une phrase à hacher : ";
    std::getline(std::cin, user_str);

    std::cout << "Résultat : " << folding_string_hash(user_str, 5000) << std::endl;

    return 0;
}