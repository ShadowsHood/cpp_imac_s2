#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include "helper.hpp"

int main() {
    std::cout << "TD 04 - Ex 02" << std::endl;

    std::string user_string {};
    std::cout << "Entrez une chaine de caracteres : ";
    std::getline(std::cin, user_string);

    std::cout << std::quoted(user_string)
              << (is_palindrome(user_string) ? " est" : " n'est pas")
              << " un palindrome"
              << std::endl;

    return 0;
}