#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include "helper.hpp"

int main() {
    std::cout << "TD 04 - Ex 02" << std::endl;

    std::vector<int> numbers {1,2,3,4,5,6,7,8,9,10};
    // for (size_t i = 0; i < 30; i++){numbers.push_back(random(0,100));}

    console_log_int(square_sum(numbers));
    console_log_int(even_sum(numbers));

    return 0;
}