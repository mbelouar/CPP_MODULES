#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>

class RPN {
    private:
        std::stack<int> _stack;
        bool    isOperator(char token);
        int     performOperation(int a, int b, char op);
    public:
        RPN();
        RPN(const RPN &src);
        RPN &operator=(const RPN &src);
        ~RPN();

        int     calculate(const std::string& expression);
};

#endif