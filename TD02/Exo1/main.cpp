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

void time_checker_it() {
    std::srand(std::time(nullptr));

    size_t iteration {500};

    size_t const size {10000};
    int const max {1000};

    // Generate a vector of random vectors (to compare the sorting algorithms on the same data set)
    std::vector<std::vector<int>> vecs {};
    // Optimization: reserve the memory for the vector of vectors as we know the size
    vecs.reserve(iteration);

    for (size_t i {0}; i < iteration; i++) {
        vecs.push_back(generate_random_vector(size, max));
    }
    
    auto display_average = [&iteration](std::string const& name, double const duration_us) {
        double const average_ms{(duration_us * 0.001) / static_cast<double>(iteration)};
            std::cout << name << " : average of " << average_ms << " ms for " << iteration << " iterations" << std::endl;
    };

    std::cout << "Sorting algorithms comparison" << std::endl;

    // reduce the number of iterations for the iterative algorithms
    iteration = 10;
    {
        ScopedTimer scopedTimer("Bubble sort", display_average);

        for(size_t i {0}; i < iteration; i++) {
            std::vector<int> vec_copy {vecs[i]};
            bubble_sort(vec_copy);
            if (!is_sorted(vec_copy)) {
                std::cerr << "Sort failed" << std::endl;
                break;
            }
        }
    }
    {
        ScopedTimer scopedTimer("Selection sort", display_average);

        for(size_t i {0}; i < iteration; i++) {
            std::vector<int> vec_copy {vecs[i]};
            selection_sort(vec_copy);
            if (!is_sorted(vec_copy)) {
                std::cerr << "Sort failed" << std::endl;
                break;
            }
        }
    }

    // restore the number of iterations
    iteration = 500;
    {
        ScopedTimer scopedTimer("Sort", display_average);

        for(size_t i {0}; i < iteration; i++) {
            std::vector<int> vec_copy {vecs[i]};
            std::sort(vec_copy.begin(), vec_copy.end());
            if (!is_sorted(vec_copy)) {
                std::cerr << "Sort failed" << std::endl;
                break;
            }
        }
    }
    {
        ScopedTimer scopedTimer("Quick sort", display_average);

        for(size_t i {0}; i < iteration; i++) {
            std::vector<int> vec_copy {vecs[i]};
            quick_sort(vec_copy);
            if (!is_sorted(vec_copy)) {
                std::cerr << "Sort failed" << std::endl;
                break;
            }
        }
    }
    {
        ScopedTimer scopedTimer("Merge sort", display_average);

        for(size_t i {0}; i < iteration; i++) {
            std::vector<int> vec_copy {vecs[i]};
            merge_sort(vec_copy);
            if (!is_sorted(vec_copy)) {
                std::cerr << "Sort failed" << std::endl;
                break;
            }
        }
    }
}

int search(std::vector<int> vec, int number){
    int left {0};
    int right {int(vec.size()- 1)};
    int indexToCheck{(right - left)/2};

    int previous_index {indexToCheck};
    while(vec[indexToCheck] != number){
        if(vec[indexToCheck] < number){
            left = indexToCheck + 1;
            indexToCheck = (right + left)/2;
            if(left==right) indexToCheck = right; //car sinon = 0

        } else {
            right = indexToCheck - 1;
            indexToCheck = (right + left)/2;
        }

        if(previous_index==indexToCheck) {
            return -1;
        } else {
            previous_index=indexToCheck;
        }
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
    counting_sort(array_test_2, *std::max_element(array_test_2.begin(), array_test_2.end()));
    cout_is_sorted(array_test_2);

    // time_checker();
    // time_checker_it();

    // std::cout << search({1, 2, 2, 3, 4, 8, 12}, 8) << std::endl;
    // std::cout << search({1, 2, 3, 3, 6, 14, 12, 15}, 15) << std::endl;
    // std::cout << search({2, 2, 3, 4, 5, 8, 12, 15, 16}, 16) << std::endl;
    // std::cout << search({5, 6, 7, 8, 9, 10, 11, 12, 13}, 6) << std::endl;
    // std::cout << search({1, 2, 3, 4, 5, 6, 7, 8, 9}, 10) << std::endl;

    return 0;
}