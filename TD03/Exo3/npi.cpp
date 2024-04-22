#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <stack>
#include "npi.hpp"


//--------------------------------HELPERS


void console_log_int(int num) {std::cout << num << std::endl;}
void console_log_str(std::string str) {std::cout << str << std::endl;}

void display_tokens(std::vector<Token> const& tokens) {
    std::cout << "Tokens : ";
    for (Token token : tokens) {
        if (token.is_operand()) {
            std::cout << token.value << " ";
        } else {
            std::cout << token.op_to_char() << ' ';
        }
    }
}

std::vector<std::string> split_string(std::string const& s) {
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

bool is_floating(std::string const& s) {
    for (char c : s) {
        if(!std::isdigit(c) && c != '.') return false;
    }
    return true;
}

void floating_checker(std::string const& s) {
    if(is_floating(s)) {
        std::cout << "Float value" << std::endl;
    } else {
        std::cout << "Non float token" << std::endl;
    }
}


Operator make_operator(char elem) {
    switch (elem){
        case '+':
            return Operator::ADD;
            break;
        case '-':
            return Operator::SUB;
            break;
        case '*':
            return Operator::MUL;
            break;
        case '/':
            return Operator::DIV;
            break;
        case '^':
            return Operator::POW;
            break;
        case '(':
            return Operator::OPEN_PAREN;
            break;
        case ')':
            return Operator::CLOSE_PAREN;
            break;
        default:
            std::cout << "Invalid operator" << std::endl;
            break;
        }
}

Token make_token(float value) {
    Token token {};
        token.type = TokenType::OPERAND;
        token.value = value;
    return token;
}

Token make_token(Operator op) {
    Token token {};
        token.type = TokenType::OPERATOR;
        token.op = op;
    return token;
}



std::vector<Token> tokenize(std::vector<std::string> const& words) {
    std::vector<Token> tokens {};

    for(std::string elem : words){
        Token new_token {is_floating(elem) ? make_token(std::stof(elem)) : make_token(make_operator(elem[0]))};
        tokens.push_back(new_token);
    }

    return tokens;
}

float npi_evaluate(std::vector<Token> const& tokens) {
    std::stack<float> npi_stack {};
    
    for (Token token : tokens) {
        if (token.is_operand()) {
            npi_stack.push(token.value);
        } else {

            if(npi_stack.size() != 2) std::cout << "error on expression" << std::endl;

            float result {};
            float rToken { npi_stack.top() };
                npi_stack.pop();
            float lToken { npi_stack.top() };
                npi_stack.pop();

            switch (token.op){
            case Operator::ADD:
                result = lToken + rToken;
                break;
            case Operator::SUB:
                result = lToken - rToken;
                break;
            case Operator::MUL:
                result = lToken * rToken;
                break;
            case Operator::DIV:
                result = lToken / rToken;
                break;
            default:
                break;
            }
            npi_stack.push(result);
        }
    }

    return npi_stack.top();
}


size_t operator_precedence(Operator const op) {
    size_t priority {0};
    switch (op) {
        case Operator::ADD:
        case Operator::SUB:
            priority = 1;
            break;
        case Operator::MUL:
        case Operator::DIV:
            priority = 2;
            break;
        case Operator::POW:
            priority = 3;
            break;
        default:
            priority = 0;
    }
    return priority;
}

std::vector<Token> infix_to_npi_tokens(std::string const& expression) {
    std::vector<Token> tokens {tokenize(split_string(expression))};
    std::vector<Token> npi_stack {};
    std::stack<Token> operator_stack {};
    size_t previous_op_prio {};

    for (Token token : tokens) {
        if (token.is_operand()) {//POURQUOI IL NE FAUT PAS DE ! (pareil pour le display) => psk operand = nombre et pas operateur
            npi_stack.push_back(token);
            std::cout << token.value << std::endl; //DEBUG
        } else {
            // std::cout << "Op : " << token.op_to_char() << std::endl;//DEBUG
            if (token.op != Operator::CLOSE_PAREN) {
                if (operator_precedence(token.op) < previous_op_prio) npi_stack.push_back(operator_stack.top());
                operator_stack.push(token);
            } else {
                while(operator_stack.top().op != Operator::OPEN_PAREN) {
                    npi_stack.push_back(operator_stack.top());
                    operator_stack.pop();
                }
                operator_stack.pop();
            }
            previous_op_prio = operator_precedence(operator_stack.top().op);
        }
    }

    return npi_stack;
}