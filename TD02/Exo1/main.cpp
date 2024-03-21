#include <vector>
#include <iostream>
#include <algorithm>
#include "sort.hpp"

using namespace std;


int main()
{
    cout << "TD 02 - Ex 01" << endl;

    std::vector<int> array1 {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> array2 {2, 5, 9, 4, 6, 3, 7, 1, 8};
    std::vector<int> array3 {5, 2, 9};

    // bubble_sort(array2);
    // selection_sort(array2);
    // quick_sort(array2);
    merge_sort(array2);
    cout_is_sorted(array2);


    return 0;
}