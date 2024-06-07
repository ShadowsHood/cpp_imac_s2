#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include "node.hpp"

int main() {
    std::cout << "TD 06 - Ex 01 & 02" << std::endl;

    // std::string user_str {};
    // std::cout << "Entrez une phrase à hacher : ";
    // std::getline(std::cin, user_str);

    std::vector<int> values {5, 3, 7, 2, 4, 6, 8, 1, 9, 0};
    // std::vector<int> values {5, 3, 8, 2, 4, 6, 7, 4, 1, 9, 0}; //Better test for all functions (remove, delete, etc.)
    Node* tree { create_tree(values) };
    std::cout << "Ordre infixe : ";
    tree->display_infixe();
    std::cout << std::endl;
    std::cout << "Min : " << min(tree) << std::endl;
    std::cout << "Max : " << max(tree) << std::endl;

    std::vector<Node const*> vector_nodes_tree {tree->prefixe()};
    int sum_values_prefixe {};
    std::cout << "Ordre prefixe : ";
    for (auto &&node : vector_nodes_tree){
        std::cout << node->value << ", ";
        sum_values_prefixe+= node->value;
    }
    std::cout << std::endl;
    std::cout << "Somme des valeurs des noeuds : " << sum_values_prefixe << std::endl;

    std::cout << "Hauteur : " << tree->height() << std::endl;

    //------------Delete childs

    // tree->left->left->delete_childs();
    // std::cout << "Ordre prefixe 2 : ";
    // std::vector<Node const*> vector_nodes_tree2 {tree->prefixe()};
    // for (auto &&node : vector_nodes_tree2){
    //     std::cout << node->value << ", ";
    // }
    // std::cout << std::endl;

    //------------Remove

    // remove(tree, 8);
    // remove(tree, 2);
    // remove(tree, 6);
    // remove(tree, 8);
    // std::cout << "Ordre prefixe 3 : ";
    // std::vector<Node const*> vector_nodes_tree3 {tree->prefixe()};
    // for (auto &&node : vector_nodes_tree3){
    //     std::cout << node->value << ", ";
    // }
    // std::cout << std::endl;

    return 0;
}