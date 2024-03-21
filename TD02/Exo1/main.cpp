#include <vector>
#include <iostream>
#include <algorithm>
#include "sort.hpp"
#include "ScopedTimer.hpp"

using namespace std;

std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

void time_checker() {
{
        std::vector<int> array {generate_random_vector(50, 100)};
        ScopedTimer timer("sort");
        std::sort(array.begin(), array.end());
    }
    {
        std::vector<int> array {generate_random_vector(50, 100)};
        ScopedTimer timer("bubble_sort");
        bubble_sort(array);
    }
    {
        std::vector<int> array {generate_random_vector(50, 100)};
        ScopedTimer timer("selection_sort");
        selection_sort(array);
    }
    {
        std::vector<int> array {generate_random_vector(50, 100)};
        ScopedTimer timer("quick_sort");
        quick_sort(array);
    }
    {
        std::vector<int> array {generate_random_vector(50, 100)};
        ScopedTimer timer("merge_sort");
        merge_sort(array);
    }
}

int search(std::vector<int> vec, int number){
    int left {0};
    int right {int(vec.size()- 1)};
    int indexToCheck{(right - left)/2};

    while(vec[indexToCheck] != number){
        if(vec[indexToCheck] < number){
            left = indexToCheck + 1;
            indexToCheck = (right + left)/2;
            if(left==right) indexToCheck = right; //car sinon = 0

        } else {
            right = indexToCheck - 1;
            indexToCheck = (right + left)/2;
        }
        // if(indexToCheck==left) return -1;
    }
    return indexToCheck;
}

int main()
{
    cout << "TD 02 - Ex 01" << endl;
    
    std::vector<int> array_test_1 {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> array_test_2 {2, 5, 9, 4, 6, 3, 7, 1, 8};
    std::vector<int> array_test_3 {5, 2, 9};

    // bubble_sort(array_test_2);
    // selection_sort(array_test_2);
    // quick_sort(array_test_2);
    // merge_sort(array_test_2);
    // cout_is_sorted(array_test_2);
    // time_checker();
    
    // std::cout << search({1, 2, 2, 3, 4, 8, 12}, 8) << std::endl;
    // std::cout << search({1, 2, 3, 3, 6, 14, 12, 15}, 15) << std::endl;
    // std::cout << search({2, 2, 3, 4, 5, 8, 12, 15, 16}, 16) << std::endl;
    // std::cout << search({5, 6, 7, 8, 9, 10, 11, 12, 13}, 6) << std::endl;
    std::cout << search({1, 2, 3, 4, 5, 6, 7, 8, 9}, 10) << std::endl;

    return 0;
}