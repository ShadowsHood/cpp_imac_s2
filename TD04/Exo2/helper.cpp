#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <stack>

void console_log_int(int num) {std::cout << num << std::endl;}
void console_log_str(std::string str) {std::cout << str << std::endl;}
int random(int const& min, int const& max){return rand() % max + 1 + min;}

auto const is_space = [](char const letter){ return letter == ' '; };

void nb_first_word(std::string const& string) {
    auto f_it { std::find_if(string.begin(), string.end(), is_space) };
    auto nb_letters {std::distance(string.begin(), string.end())};
    if(f_it != string.end()) {
        nb_letters = std::distance(string.begin(), f_it);
    }
    std::cout << "Le nombre de lettres du premier mot : " << nb_letters << std::endl;
}

std::vector<std::string> split_string(std::string const& str) {
    std::vector<std::string> words {};

    auto nb_spaces {std::count_if(str.cbegin(), str.cend(), is_space)};
    auto begin {str.cbegin()};

    for (int i {0}; i < nb_spaces; i++) {
        auto f_it {std::find_if(begin, str.cend(), is_space)};
        std::string word{begin, f_it};
        words.push_back(word);
        begin = f_it+1;
    }
    if(begin != str.cend()) {
        std::string last_word{begin, str.cend()};
        words.push_back(last_word);
    } 

    return words;
}