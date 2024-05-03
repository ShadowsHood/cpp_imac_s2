#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <iterator>
#include "node.hpp"

void console_log_int(int num) {std::cout << num << std::endl;}
void console_log_str(std::string str) {std::cout << str << std::endl;}
int random(int const& min, int const& max){return rand() % max + 1 + min;}


Node* create_node(int value) {
    Node* node { new Node {value, nullptr, nullptr}};
    return node;
}

bool Node::is_leaf() const {
    return (left == nullptr) && (right == nullptr);
}

void Node::insert(int value) {
    Node* new_node {create_node(value)};
    (value < this->value) ? left = new_node : right = new_node;
}

int Node::height() const {
    int height {0};
    
    if (!is_leaf()) {
        int left_height {left ? left->height() : 0};
        int right_height {right ? right->height() : 0};
        height = (left_height <= right_height) ? right_height++ : left_height++;
    } else {
        height = 1;
    }

    return height;
}

void Node::delete_childs() {
    if (!is_leaf()) {
        if(left) left->delete_childs();
        if(right) right->delete_childs();
    }
    delete this;
}

void Node::display_infixe() const {
    if (!is_leaf()) {
        if(left) left->display_infixe();
        std::cout << value << " ";
        if(right) right->display_infixe();
    } else {
        std::cout << value << " ";
    }
}

std::vector<Node const*> Node::prefixe() const {

    std::vector<Node const*> node_list {};

    node_list.push_back(this);
    if (!is_leaf()) {
        if(left) {
            std::vector<Node const*> left_nodes {left->prefixe()}; 
            node_list.insert(node_list.end(), left_nodes.begin(), left_nodes.end());
        }
        if(right) {
            std::vector<Node const*> right_nodes {right->prefixe()};
            node_list.insert(node_list.end(), right_nodes.begin(), right_nodes.end());
        }
    }

    return node_list;
}


std::vector<Node const*> Node::postfixe() const {
    std::vector<Node const*> nodes {};
    std::stack<Node const*> stack_process {};
    Node const* previous {nullptr};
    stack_process.push(this);

    while (!stack_process.empty()) {
        Node const* current { stack_process.top() };

        // Si on est en train de descendre dans l'arbre
        if (previous == nullptr || (previous->left == current || previous->right == current)) {
            if(current->left) {
                stack_process.push(current->left);
            }
            else if(current->right) {
                stack_process.push(current->right);
            } else {
                // on traite le nœud (ajouter au vecteur) et on le retire de la pile
                nodes.push_back(current);
                stack_process.pop();
            }

        // Si l'on remonte dans l'arbre en venant de la gauche
        }else if (previous == current->left) {
            if(current->right) {
                stack_process.push(current->right);
            } else {
                nodes.push_back(current);
                stack_process.pop();
            }

        // Si l'on remonte dans l'arbre en venant de la droite
        } else if (previous == current->right) {
            nodes.push_back(current);
            stack_process.pop();
        }

        previous = current;

    }
    return nodes;
}

Node*& most_left(Node*& node) {
    return node->left ? most_left(node->left) : node;
}

bool remove(Node*& node, int value) {
    if (value == node->value && node->is_leaf()) {
        delete_node(node);
        // on retourne true car la suppression a été effectuée
        return true;
    } else if (value == node->value && !node->is_leaf()) {
        if (node->left && node->right) {

        } else if (node->left) {

        } else {
            
        }
    } else {
        // pas la bonne value
        //je go chercher le bon node
    }
}

void delete_node(Node*& node) {
    // On supprime le nœud courant
    delete node;
    // Comme on a une référence sur le pointeur du nœud courant, on le met à jour avec nullptr
    // Ainsi le parent du nœud courant aura un pointeur vers nullptr
    node = nullptr;
}







void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left) {
    if (node.right) {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left) {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const& node) {
    pretty_print_left_right(node, "", true);
}