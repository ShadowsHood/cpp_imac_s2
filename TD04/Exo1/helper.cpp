#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <stack>

void console_log_int(int num) {std::cout << num << std::endl;}
void console_log_str(std::string str) {std::cout << str << std::endl;}
int random(int const& min, int const& max){return rand() % max + 1 + min;}

void display_find_vec(std::vector<int> const& vec, int const& value) {
    auto f_it { std::find(vec.begin(), vec.end(), value) };
    if(f_it != vec.end()) {
        std::cout << "Le nombre : " << *f_it << ", se trouve bien dans le tableau" << std::endl;
    } else {
        std::cout << "Le nombre " << value << " n'existe PAS dans le tableau" << std::endl;
    }
}

void display_count(std::vector<int> const& vec, int const& value) {
    std::cout << "Il y a " << std::count(vec.begin(), vec.end(), value) << " fois la valeur " << value << " dans le tableau" << std::endl;
}