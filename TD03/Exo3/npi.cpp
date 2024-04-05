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

std::vector<std::string> split_string(std::string const& s) {
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

bool is_floating(std::string const& s) {
    for (char c : s) {
        if(std::isdigit(c) || c == '.') {
            continue;
        } else {
            return false;}
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