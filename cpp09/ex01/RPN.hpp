#pragma once

#include <iostream>
#include <string>
#include <stack>


class RPN {
    public:
        RPN();
        ~RPN();
        RPN(const RPN &cpy);
        RPN &operator=(const RPN &src);

        void calculate(std::string str);

    private:
        std::stack<int> _num;
        
        bool handletoken(char c);
        bool istoken(char c);

};