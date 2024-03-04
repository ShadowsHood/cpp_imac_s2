#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool is_sorted(std::vector<int> const& vec) { return std::is_sorted(vec.begin(), vec.end()); }

int main()
{
    cout << "TD 02 - Ex 01" << endl;

    std::vector<int> array {1, 2, 3, 4, 5, 6, 7, 8, 9};
    if (is_sorted(array)) {
        std::cout << "Le tableau est trié" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }

    return 0;
}