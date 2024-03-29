# pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <stack>

void console_log_int(int num);
void console_log_str(std::string str);

enum class Operator { ADD, SUB, MUL, DIV, OPEN_PAREN, CLOSE_PAREN};
enum class TokenType { OPERATOR, OPERAND };
struct Token {
    TokenType type;
    float value;
    Operator op;
};

Token make_token(float value);
Token make_token(Operator op);

std::vector<std::string> split_string(std::string const& s);

bool is_floating(std::string const& s);
void floating_checker(std::string const& s);


void npi_calc(std::stack<float> & npi_stack, char op);
float npi_evaluate(std::vector<std::string> const& tokens);