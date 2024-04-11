#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include "cards.hpp"

// namespace std {
//     template<>
//     struct hash<Card> {
//         size_t operator()(Card const& card) const {
//             return card.hash();
//         }
//     };
// }

int main() {
    std::cout << "TD 05 - Ex 03" << std::endl;

    std::vector<Card> cards {get_cards(100)};
    display_card_list(number_of_cards(cards));

    return 0;
}