#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_map>
#include "cards.hpp"

void console_log_int(int num) {std::cout << num << std::endl;}
void console_log_str(std::string str) {std::cout << str << std::endl;}
int random(int const& min, int const& max){return rand() % max + 1 + min;}

std::vector<Card> get_cards(size_t const size) {
    std::vector<Card> cards {};
    cards.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}

std::string card_name(Card const& card) {
    std::string name {};

    unsigned int card_value {(static_cast<unsigned int>(card.value)+2) % 14};

    if (card_value < 10) {
        name += '0' + card_value;
    }else if (card_value == 10) {
        name += "10";
    }else if (card_value == 11) {
        name += 'V';
    }else if (card_value == 12) {
        name += 'Q';
    }else if (card_value == 13) {
        name += 'K';
    }

    name += " of ";

    if (card.kind == CardKind::Heart) {
        name += "Heart";
    }else if (card.kind == CardKind::Diamond) {
        name += "Diamond";
    }else if (card.kind == CardKind::Club) {
        name += "Club";
    }else if (card.kind == CardKind::Spade) {
        name += "Spade";
    }
    return name;
}

std::unordered_map<std::string, int> number_of_cards(std::vector<Card> const& cardS) {
    std::unordered_map<std::string, int> cardList {};
    for (Card card : cardS) {
        std::string name {card_name(card)};
        auto cardName {cardList.find(name)};
        if (cardName != cardList.end()) {
            cardName->second++;
        } else {
            cardList.insert(std::make_pair(name, 1));
        }
    }
    return cardList;
}

void display_card_list(std::unordered_map<std::string, int> const& liste) {
    for (auto card : liste) {
        std::cout << card.first <<" : "<< card.second << std::endl;
    }
}
