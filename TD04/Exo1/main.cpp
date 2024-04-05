#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <numeric>
#include <algorithm>
#include "helper.hpp"

int main() {
    std::cout << "TD 04 - Ex 01" << std::endl;

    // std::vector<int> numbers {1,2,3,4,5,6,7,8,9,10,3};
    std::vector<int> numbers {};
    for (size_t i = 0; i < 30; i++){numbers.push_back(random(0,100));}

    for (std::vector<int>::iterator it { numbers.begin() }; it != numbers.end(); ++it) {
        std::cout << *it << std::endl;
    }

    display_find_vec(numbers, 3);
    display_find_vec(numbers, 110);

    display_count(numbers, 3);
    display_count(numbers, 110);

    std::sort(numbers.begin(), numbers.end());

    int sum { std::accumulate(numbers.begin(), numbers.end(), 0, [](int acc, int current_element) { return acc + current_element; }) };
    std::cout << "La some des elements de mon tableau est : " << sum << std::endl;

    return 0;
}