# pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_map>

enum class CardKind {
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card {
    CardKind kind;
    CardValue value;

    int hash() {
        int hash {static_cast<int>(kind)*(static_cast<int>(CardValue::Ace)+1)+static_cast<int>(value)};
        return hash;
    }
};

//------------------Soit disant déjà definie

// bool operator==(Card const& a, Card const& b) {
//     return a.kind == b.kind && a.value == b.value;
// }


void console_log_int(int num);
void console_log_str(std::string str);
int random(int const& min, int const& max);
std::vector<Card> get_cards(size_t const size);
std::string card_name(Card const& card);
std::unordered_map<std::string, int> number_of_cards(std::vector<Card> const& cardS);
void display_card_list(std::unordered_map<std::string, int> const& liste);