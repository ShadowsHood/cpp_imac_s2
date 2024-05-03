# pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>

void console_log_int(int num);
void console_log_str(std::string str);
int random(int const& min, int const& max);

struct Node {
    int value;
    Node* left { nullptr };
    Node* right { nullptr };

    bool is_leaf() const;
    void insert(int value);
    int height() const;
    void delete_childs();

    void display_infixe() const;
    std::vector<Node const*> prefixe() const;
    std::vector<Node const*> postfixe() const;
};

Node*& most_left(Node*& node);
bool remove(Node*& node, int value);

void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left);
void pretty_print_left_right(Node const& node);

Node* create_node(int value);