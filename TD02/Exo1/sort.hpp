# pragma once
#include <iostream>
#include <vector>

void bubble_sort(std::vector<int> & vec);
void selection_sort(std::vector<int> & vec);

template<typename T>
size_t quick_sort_partition(std::vector<T> & vec, size_t left, size_t right);
void quick_sort(std::vector<int> & vec, size_t const left, size_t const right);
void quick_sort(std::vector<int> & vec);