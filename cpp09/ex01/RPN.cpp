#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN &cpy) : _num(cpy._num) {}
RPN &RPN::operator=(const RPN &src) {
    if (this != &src)
        _num = src._num;
    return *this;
}

bool RPN::istoken(char c){
    std::string tokens  = "+-/*";
    if (tokens.find(c) != std::string::npos)
        return true;
    return false;
}

bool RPN::handletoken(char c) {
    int result = 0;
    int first_n = this->_num.top();
    this->_num.pop();
    int second_n = this->_num.top();
    this->_num.pop();
    if (c == '+') result = second_n + first_n;
    else if (c == '-') result = second_n - first_n;
    else if (c == '*') result = second_n * first_n;
    else if (c == '/') {
        if (first_n == 0) {
            std::cerr << "Error: division by zero" << std::endl;
            return false;
        }
        result = second_n / first_n;
    }
    this->_num.push(result);
    return true;
}

void RPN::calculate(std::string str) {
    if (str.length() < 5) {
        std::cerr << "Error: invalid input" << std::endl;
        return;
    }
    
    for (size_t i = 0; i < str.length(); i++) {
        char c = str[i];
        if (i % 2 == 1 && c != ' ') {
            std::cerr << "Error: invalid input" << std::endl;
            return;
        }
        if (i % 2 == 0) {
            if (isdigit(c))
                this->_num.push(c - '0');
            else if (istoken(c)) {
                if (this->_num.size() < 2) {
                    std::cerr << "Error: not enough operands" << std::endl;
                    return;
                }
                if (!handletoken(c))
                    return;
            }
        }
    }
    if (this->_num.size() != 1) {
        std::cerr << "Error: invalid expression" << std::endl;
        return;
    }
    std::cout << this->_num.top() << std::endl;
}