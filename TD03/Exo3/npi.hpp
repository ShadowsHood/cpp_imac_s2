# pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <stack>

void console_log_int(int num);
void console_log_str(std::string str);

enum class Operator { ADD, SUB, MUL, DIV, POW, OPEN_PAREN, CLOSE_PAREN};
enum class TokenType { OPERATOR, OPERAND };
struct Token {
    TokenType type;
    float value;
    Operator op;

    bool is_operand(){
        // return this->type == TokenType::OPERAND ? true : false;
        return this->type == TokenType::OPERAND;
    }

    char op_to_char() {
        char opToChar {};
        switch (this->op){
            case Operator::ADD:
                opToChar = '+';
                break;
            case Operator::SUB:
                opToChar = '-';
                break;
            case Operator::MUL:
                opToChar = '*';
                break;
            case Operator::DIV:
                opToChar = '/';
                break;
            case Operator::POW:
                opToChar = '^';
                break;
            case Operator::OPEN_PAREN:
                opToChar = '(';
                break;
            case Operator::CLOSE_PAREN:
                opToChar = ')';
                break;
            default:
                opToChar = '_';
                break;
        }
        return opToChar;
    }
};

std::vector<std::string> split_string(std::string const& s);

//Exo 2
Token make_token(float value);
Token make_token(Operator op);
std::vector<Token> tokenize(std::vector<std::string> const& words);
float npi_evaluate(std::vector<Token> const& tokens);

//Exo 3
size_t operator_precedence(Operator const op);
std::vector<Token> infix_to_npi_tokens(std::string const& expression);
void display_tokens(std::vector<Token> const& tokens);