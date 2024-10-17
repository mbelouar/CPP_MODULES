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
        bool isOperator(const std::string& token);
        int performOperation(int a, int b, const std::string& op);
    public:
        RPN();
        RPN(const RPN &src);
        RPN &operator=(const RPN &src);
        ~RPN();

        std::stack<int> getStack() const;
        int calculate(const std::string& expression);
};

#endif