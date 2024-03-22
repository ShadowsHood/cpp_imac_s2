#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>

void console_log_int(int num) {std::cout << num << std::endl;}
void console_log_str(std::string str) {std::cout << str << std::endl;}

std::ostream& operator<<(std::ostream& os, std::vector<int> const& vec) {
    for (int num : vec) {
        os << num;
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

// -----------------------BUBBLE SORT

void bubble_sort(std::vector<int> & vec) {
    bool change {true};
    while (change) {
        change = false;
        for (int i = 0; i < vec.size()-1; i++) {
            if (vec[i]>vec[i+1]) {
                std::swap(vec[i], vec[i+1]);
                change = true;
            }
        }
        // cout << vec << endl;
    }
}

// -----------------------SELECTION SORT

void selection_sort(std::vector<int> & vec) {
    for (int startIndex = 0; startIndex < vec.size()-1; startIndex++) {
        int minIndex {startIndex};
        for (int i = startIndex; i < vec.size(); i++) {
            if (vec[i] < vec[minIndex]) minIndex = i;
        }
        if (minIndex != startIndex ) std::swap(vec[startIndex], vec[minIndex]);
        // cout << vec << endl;
    }
}

// -----------------------QUICK SORT

// l'idée de cette fonction est de prendre le vecteur sur lequel on va travailler en paramètre et de prendre deux index (left et right) qui indiquent la partie du tableau pour laquelle on va répartir les valeurs (inférieur au pivot à gauche supérieur à droite du pivot réciproquement à droite) et la valeur du pivot
template<typename T>
size_t quick_sort_partition(std::vector<T> & vec, size_t left, size_t right) {
    // Pivot : dernier
    size_t const pivot {right};
    
    // index premier élément plus grand que pivot
    size_t first_bigger { left };

    for (size_t i {left}; i < right ;i++) {
        if (vec[i] < vec[pivot]) {
            std::swap(vec[i], vec[first_bigger]);
            first_bigger ++;
        }
    }
    // place le pivot au milieu
    std::swap(vec[right], vec[first_bigger]);
    // index du pivot
    return first_bigger;
}

void quick_sort(std::vector<int> & vec, size_t const left, size_t const right) {
    if (left >= right) return;

    int pivot_index = quick_sort_partition(vec, left, right);

    if (pivot_index < right-1)quick_sort(vec, pivot_index+1, right);
    if (pivot_index > left+1)quick_sort(vec, left, pivot_index-1);
}
// Surcharge de la fonction qui permet d'appeler la fonction en passant seulement le vecteur et définir les index left et right pour cibler la totalité du tableau à trier automatiquement
void quick_sort(std::vector<int> & vec) {
    quick_sort(vec, 0, vec.size() - 1);
}

// -----------------------MERGE SORT

void merge_sort_merge(std::vector<int> & vec, size_t const left, size_t const middle, size_t const right) {
    // On crée deux vecteurs temporaires pour stocker les copies des deux sous-parties à fusionner
    std::vector<float> left_vec(vec.begin() + left, vec.begin() + middle + 1);
    std::vector<float> right_vec(vec.begin() + middle + 1, vec.begin() + right + 1);
    size_t const left_size { left_vec.size() };
    size_t const right_size { right_vec.size() };

    // Deux index pour parcourir les deux sous-parties et remplir le vecteur original
    size_t left_index {0};
    size_t right_index {0};

    for (int i = left; i <= right; i++)
    {
        if (left_index < left_size && right_index < right_size)
        {
            if (left_vec[left_index] <= right_vec[right_index]) {
                vec[i] = left_vec[left_index];
                left_index++;
            } else {
                vec[i] = right_vec[right_index];
                right_index++;
            }
        } else if (left_index >= left_size && right_index < right_size) {
            vec[i] = right_vec[right_index];
            right_index++;
        } else if (right_index >= right_size && left_index < left_size) {
            vec[i] = left_vec[left_index];
            left_index++;
        } else {
            console_log_str("WTF bro !");
        }
    }
}

void merge_sort(std::vector<int> & vec, size_t const left, size_t const right) {
    if (left >= right)return;
    // 1. Choix de l'index au milieu de la partition
    int middle = (right+left)/2;

    // 2. Appels récursifs sur les deux sous-parties
    merge_sort(vec, left, middle);
    merge_sort(vec, middle+1, right);

    // 3. Fusion des deux sous-parties
    merge_sort_merge(vec, left, middle, right);
}
void merge_sort(std::vector<int> & vec) {
    merge_sort(vec, 0, vec.size() - 1);
}

// -----------------------COUNTING SORT

void counting_sort(std::vector<int> & vec, int const max)  {
    std::vector<int> occur {};

    occur.resize(max+1,0);

    for(int number : vec) {
        occur[number]++;
    }
    vec.clear();

    for (size_t i = 0; i < occur.size(); i++) {
        if (occur[i] != 0) {
            for (size_t j = 0; j < occur[i]; j++) {
                vec.push_back(i);
            }
        }
    }
    
}