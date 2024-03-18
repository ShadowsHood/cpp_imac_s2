#include <vector>
#include <iostream>
#include <algorithm>
#include "sort.hpp"

using namespace std;

std::ostream& operator<<(std::ostream& os, std::vector<int> const& vec) {
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i];
        os << ", ";
    }
    return os;
}

bool is_sorted(std::vector<int> const& vec) { return std::is_sorted(vec.begin(), vec.end()); }
void cout_is_sorted(std::vector<int> const& vec) {
    if (is_sorted(vec)) {std::cout << "Le tableau est trié" << std::endl;} 
    else {
        std::cout << "Le tableau n'est PAS trié" << std::endl;
        std::cout << vec << std::endl;
    }
}


int main()
{
    cout << "TD 02 - Ex 01" << endl;

    std::vector<int> array1 {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> array2 {2, 5, 9, 4, 6, 3, 7, 1, 8};
    std::vector<int> array3 {5, 2, 9};

    // bubble_sort(array2);
    // selection_sort(array2);
    quick_sort(array3);
    // merge_sort(array2);
    cout_is_sorted(array3);


    return 0;
}