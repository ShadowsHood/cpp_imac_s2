#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <stack>

void console_log_int(int num) {std::cout << num << std::endl;}
void console_log_str(std::string str) {std::cout << str << std::endl;}
int random(int const& min, int const& max){return rand() % max + 1 + min;}

bool is_palindrome(std::string const& str) {
    return std::equal(str.cbegin(), str.cbegin() + str.size() / 2, str.crbegin());
}