#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <stack>

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

void npi_calc(std::stack<float> & npi_stack, char op) {
    float rToken { npi_stack.top() };
        npi_stack.pop();
    float lToken { npi_stack.top() };
        npi_stack.pop();

    float result {};

        switch (op){
        case '+':
            result = lToken + rToken;
            break;
        case '-':
            result = lToken - rToken;
            break;
        case '*':
            result = lToken * rToken;
            break;
        case '/':
            result = lToken / rToken;
            break;
        default:
            break;
        }

    npi_stack.push(result);
}

float npi_evaluate(std::vector<std::string> const& tokens) {
    std::stack<float> npi_stack {};

    for(std::string token : tokens){
        is_floating(token) ? npi_stack.push(std::stof(token)) : npi_calc(npi_stack, token[0]);
    }

    return npi_stack.top();
}
