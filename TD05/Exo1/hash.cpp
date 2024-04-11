#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <stack>

void console_log_int(int num) {std::cout << num << std::endl;}
void console_log_str(std::string str) {std::cout << str << std::endl;}

size_t folding_string_hash(std::string const& s, size_t max) {
   
    size_t hash {};
    for (char c : s) {
        hash = (hash+c)%max;
    }
    return hash;
}

size_t folding_string_ordered_hash(std::string const& s, size_t max) {
    size_t hash {};
    for (size_t i {0}; i < s.length(); i++) {
        hash = (hash+s[i]*i)%max;
    }
    return hash;
}

size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m) {
    size_t hash {};
    int power {1};
    for (size_t i {0}; i < s.length(); i++) {
        hash = (hash+s[i]*power)%m;
        power *= p;
    }
    return hash;
}