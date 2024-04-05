#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <numeric>

void console_log_int(int num) {std::cout << num << std::endl;}
void console_log_str(std::string str) {std::cout << str << std::endl;}
int random(int const& min, int const& max){return rand() % max + 1 + min;}

int square_sum(const std::vector<int>& vec) {
    return std::accumulate(
        vec.begin(), 
        vec.end(), 
        0, 
        [](int accumulator, int current_element) { return accumulator + current_element * current_element; }
    );
}
int even_sum(const std::vector<int>& vec) {
    return std::accumulate(
        vec.begin(), 
        vec.end(), 
        1, 
        [](int acc, int el) { return el % 2 == 0 ? acc*el : acc; }
    );
}