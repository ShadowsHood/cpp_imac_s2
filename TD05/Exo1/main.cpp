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

    std::cout << "Hash basique : " << folding_string_hash(user_str, 5000) << std::endl;
    std::cout << "Hash index : " << folding_string_ordered_hash(user_str, 5000) << std::endl;
    // std::cout << "Polynomial rolling hash : " << polynomial_rolling_hash(user_str, 5000) << std::endl;

    return 0;
}