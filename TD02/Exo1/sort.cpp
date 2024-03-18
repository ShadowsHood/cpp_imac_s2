#include <iostream>
#include <vector>
#include <algorithm>

void console_log_int(int num) {std::cout << num << std::endl;}

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