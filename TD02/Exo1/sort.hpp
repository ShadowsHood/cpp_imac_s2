# pragma once
#include <iostream>
#include <vector>
#include <algorithm>

std::ostream& operator<<(std::ostream& os, std::vector<int> const& vec);
bool is_sorted(std::vector<int> const& vec);
void cout_is_sorted(std::vector<int> const& vec);

void bubble_sort(std::vector<int> & vec);
void selection_sort(std::vector<int> & vec);

template<typename T>
size_t quick_sort_partition(std::vector<T> & vec, size_t left, size_t right);
void quick_sort(std::vector<int> & vec, size_t const left, size_t const right);
void quick_sort(std::vector<int> & vec);

void merge_sort_merge(std::vector<int> & vec, size_t const left, size_t const middle, size_t const right);
void merge_sort(std::vector<int> & vec, size_t const left, size_t const right);
void merge_sort(std::vector<int> & vec);