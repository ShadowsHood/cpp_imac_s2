#include <vector>
#include <iostream>
#include <algorithm>

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
    else {std::cout << "Le tableau n'est PAS trié" << std::endl;}
}

void bubble_sort(std::vector<int> & vec) {
    bool change {true};
    while (change) {
        change = false;
        for (int i = 0; i < vec.size()-1; i++) {
            if (vec[i]>vec[i+1]) {
                swap(vec[i], vec[i+1]);
                change = true;
            }
        }
        // cout << vec << endl;
    }
}

void selection_sort(std::vector<int> & vec) {
    for (int startIndex = 0; startIndex < vec.size()-1; startIndex++) {
        int minIndex {startIndex};
        for (int i = startIndex; i < vec.size(); i++) {
            if (vec[i] < vec[minIndex]) minIndex = i;
        }
        if (minIndex != startIndex ) swap(vec[startIndex], vec[minIndex]);
        // cout << vec << endl;
    }
}

size_t quick_sort_partition(std::vector<float> & vec, size_t left, size_t right, size_t const pivot);
void quick_sort(std::vector<float> & vec, size_t const left, size_t const right);
void quick_sort(std::vector<float> & vec) {
    quick_sort(vec, 0, vec.size() - 1);
}

void merge_sort_merge(std::vector<float> & vec, size_t const left, size_t const middle, size_t const right);
void merge_sort(std::vector<float> & vec, size_t const left, size_t const right);
void merge_sort(std::vector<float> & vec) {
    merge_sort(vec, 0, vec.size() - 1);
}

int main()
{
    cout << "TD 02 - Ex 01" << endl;

    std::vector<int> array1 {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> array2 {2, 5, 9, 4, 6, 3, 7, 1, 8};

    // bubble_sort(array2);
    // selection_sort(array2);
    quick_sort(array2);
    cout_is_sorted(array2);


    return 0;
}