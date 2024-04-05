#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <numeric>
#include <algorithm>
#include "helper.hpp"

int main() {
    std::cout << "TD 04 - Ex 02" << std::endl;

    std::string user_string {};
    std::cout << "Entrez une chaine de caracteres : ";
    std::getline(std::cin, user_string);

    nb_first_word(user_string);

    std::vector<std::string> words {split_string(user_string)};
    for (std::string str : words) {
        console_log_str(str);
    }
    

    return 0;
}