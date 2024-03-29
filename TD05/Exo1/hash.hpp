# pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <stack>

void console_log_int(int num);
void console_log_str(std::string str);

size_t folding_string_hash(std::string const& s, size_t max);
size_t folding_string_ordered_hash(std::string const& s, size_t max);
size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m);