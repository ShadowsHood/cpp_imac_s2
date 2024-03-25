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