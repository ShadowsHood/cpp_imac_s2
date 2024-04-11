#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include "robots.hpp"

int main() {
    std::cout << "TD 05 - Ex 02" << std::endl;

    auto listeRepairs {robots_fixes_map(get_robots_fix(20))};
    // display_robots_map(listeRepairs);
    display_robots_cost(listeRepairs);

    return 0;
}