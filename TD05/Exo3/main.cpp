#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include "cards.hpp"

int main() {
    std::cout << "TD 05 - Ex 03" << std::endl;

    std::vector<Card> cards {get_cards(100)};
    display_card_list(number_of_cards(cards));

    return 0;
}